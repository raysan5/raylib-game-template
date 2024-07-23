const std = @import("std");
const builtin = @import("builtin");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const all = b.step("pong", "pong");

    var dir = try std.fs.cwd().openDir("src", .{ .iterate = true });

    defer if (comptime builtin.zig_version.minor >= 12) dir.close();
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);

    defer arena.deinit();
    const allocator = arena.allocator();

    var iter = try dir.walk(allocator);
    defer iter.deinit();

    const exe = b.addExecutable(.{
        .name = "pong",
        .target = target,
        .optimize = optimize,
    });

    exe.linkLibC();

    exe.addObjectFile(switch (target.result.os.tag) {
        .windows => b.path("raylib/zig-out/lib/raylib.lib"),
        .linux => b.path("raylib/zig-out/lib/libraylib.a"),
        .macos => b.path("raylib/zig-out/lib/libraylib.a"),
        .emscripten => b.path("raylib/zig-out/lib/libraylib.a"),
        else => @panic("Unsupported OS"),
    });

    exe.addIncludePath(b.path("raylib/src"));
    exe.addIncludePath(b.path("raylib/src/external"));
    exe.addIncludePath(b.path("raylib/src/external/glfw/include"));

    switch (target.result.os.tag) {
        .windows => {
            std.debug.print("running on windows\n", .{});
            exe.linkSystemLibrary("winmm");
            exe.linkSystemLibrary("gdi32");
            exe.linkSystemLibrary("opengl32");

            exe.defineCMacro("PLATFORM_DESKTOP", null);
        },
        .linux => {
            exe.linkSystemLibrary("GL");
            exe.linkSystemLibrary("rt");
            exe.linkSystemLibrary("dl");
            exe.linkSystemLibrary("m");
            exe.linkSystemLibrary("X11");

            exe.defineCMacro("PLATFORM_DESKTOP", null);
        },
        .macos => {
            exe.linkFramework("Foundation");
            exe.linkFramework("Cocoa");
            exe.linkFramework("OpenGL");
            exe.linkFramework("CoreAudio");
            exe.linkFramework("CoreVideo");
            exe.linkFramework("IOKit");

            exe.defineCMacro("PLATFORM_DESKTOP", null);
        },
        else => {
            @panic("Unsupported OS");
        },
    }
    while (try iter.next()) |entry| {
        if (entry.kind != .file) continue;

        _ = std.mem.lastIndexOf(u8, entry.basename, ".c") orelse continue;
        const path = try std.fs.path.join(b.allocator, &.{ "src", entry.path });

        std.debug.print("path {s}\n", .{path});

        exe.addCSourceFile(.{ .file = b.path(path), .flags = &.{} });
    }

    const install_cmd = b.addInstallArtifact(exe, .{});

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(&install_cmd.step);

    const run_step = b.step("run pong", "pooong");
    run_step.dependOn(&run_cmd.step);

    all.dependOn(&install_cmd.step);

    const allOut = b.getInstallStep();
    allOut.dependOn(all);
}
