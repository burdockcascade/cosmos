#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_window(sol::state& lua) {

    // Window Namespace
    sol::table window_namespace = lua.create_named_table("Window");

    // Lifecycle
    window_namespace.set_function("Init", InitWindow);
    window_namespace.set_function("Close", CloseWindow);
    window_namespace.set_function("ClearBackground", ClearBackground);
    window_namespace.set_function("ShouldClose", WindowShouldClose);
    window_namespace.set_function("SetTargetFPS", SetTargetFPS);

    // State
    window_namespace.set_function("IsReady", IsWindowReady);
    window_namespace.set_function("IsFullscreen", IsWindowFullscreen);
    window_namespace.set_function("IsHidden", IsWindowHidden);
    window_namespace.set_function("IsMinimized", IsWindowMinimized);
    window_namespace.set_function("IsMaximized", IsWindowMaximized);
    window_namespace.set_function("IsFocused", IsWindowFocused);
    window_namespace.set_function("IsResized", IsWindowResized);
    window_namespace.set_function("IsState", IsWindowState);
    window_namespace.set_function("SetState", SetWindowState);
    window_namespace.set_function("ClearState", ClearWindowState);
    window_namespace.set_function("ToggleFullscreen", ToggleFullscreen);
    window_namespace.set_function("Maximize", MaximizeWindow);
    window_namespace.set_function("Minimize", MinimizeWindow);
    window_namespace.set_function("Restore", RestoreWindow);
    window_namespace.set_function("TakeScreenshot", TakeScreenshot);

    // Monitor
    window_namespace.set_function("GetCurrentMonitor", GetCurrentMonitor);
    window_namespace.set_function("GetMonitorCount", GetMonitorCount);
    window_namespace.set_function("GetMonitorWidth", GetMonitorWidth);
    window_namespace.set_function("GetMonitorHeight", GetMonitorHeight);
    window_namespace.set_function("GetMonitorPhysicalWidth", GetMonitorPhysicalWidth);
    window_namespace.set_function("GetMonitorPhysicalHeight", GetMonitorPhysicalHeight);
    window_namespace.set_function("GetMonitorName", GetMonitorName);
    window_namespace.set_function("GetMonitorPosition", GetMonitorPosition);
    window_namespace.set_function("GetMonitorRefreshRate", GetMonitorRefreshRate);

    // Cursor   
    window_namespace.set_function("ShowCursor", ShowCursor);
    window_namespace.set_function("HideCursor", HideCursor);
    window_namespace.set_function("IsCursorHidden", IsCursorHidden);
    window_namespace.set_function("EnableCursor", EnableCursor);
    window_namespace.set_function("DisableCursor", DisableCursor);
    window_namespace.set_function("IsCursorOnScreen", IsCursorOnScreen);

    // Modes
    window_namespace.set_function("BeginDrawing", BeginDrawing);
    window_namespace.set_function("EndDrawing", EndDrawing);
    window_namespace.set_function("BeginMode2D", BeginMode2D);
    window_namespace.set_function("EndMode2D", EndMode2D);
    window_namespace.set_function("BeginMode3D", BeginMode3D);
    window_namespace.set_function("EndMode3D", EndMode3D);

}