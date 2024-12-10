#include <sol/sol.hpp>
#include <raylib.h>
#include "modules.hpp"

void bind_raylib_input(sol::state& lua) {

    // Mouse Constants
    SET_GLOBAL_CONSTANT(MOUSE_BUTTON_LEFT);
    SET_GLOBAL_CONSTANT(MOUSE_BUTTON_RIGHT);
    SET_GLOBAL_CONSTANT(MOUSE_BUTTON_MIDDLE);
    SET_GLOBAL_CONSTANT(MOUSE_BUTTON_SIDE);
    SET_GLOBAL_CONSTANT(MOUSE_BUTTON_EXTRA);
    SET_GLOBAL_CONSTANT(MOUSE_BUTTON_FORWARD);
    SET_GLOBAL_CONSTANT(MOUSE_BUTTON_BACK);

    // Gesture Constants
    SET_GLOBAL_CONSTANT(GESTURE_NONE);
    SET_GLOBAL_CONSTANT(GESTURE_TAP);
    SET_GLOBAL_CONSTANT(GESTURE_DOUBLETAP);
    SET_GLOBAL_CONSTANT(GESTURE_HOLD);
    SET_GLOBAL_CONSTANT(GESTURE_DRAG);
    SET_GLOBAL_CONSTANT(GESTURE_SWIPE_RIGHT);
    SET_GLOBAL_CONSTANT(GESTURE_SWIPE_LEFT);
    SET_GLOBAL_CONSTANT(GESTURE_SWIPE_UP);
    SET_GLOBAL_CONSTANT(GESTURE_SWIPE_DOWN);
    SET_GLOBAL_CONSTANT(GESTURE_PINCH_IN);
    SET_GLOBAL_CONSTANT(GESTURE_PINCH_OUT);

    // Keyboard Constants
    SET_GLOBAL_CONSTANT(KEY_SPACE);
    SET_GLOBAL_CONSTANT(KEY_ESCAPE);
    SET_GLOBAL_CONSTANT(KEY_ENTER);
    SET_GLOBAL_CONSTANT(KEY_TAB);
    SET_GLOBAL_CONSTANT(KEY_BACKSPACE);
    SET_GLOBAL_CONSTANT(KEY_INSERT);
    SET_GLOBAL_CONSTANT(KEY_DELETE);
    SET_GLOBAL_CONSTANT(KEY_RIGHT);
    SET_GLOBAL_CONSTANT(KEY_LEFT);
    SET_GLOBAL_CONSTANT(KEY_DOWN);
    SET_GLOBAL_CONSTANT(KEY_UP);
    SET_GLOBAL_CONSTANT(KEY_PAGE_UP);
    SET_GLOBAL_CONSTANT(KEY_PAGE_DOWN);
    SET_GLOBAL_CONSTANT(KEY_HOME);
    SET_GLOBAL_CONSTANT(KEY_END);
    SET_GLOBAL_CONSTANT(KEY_CAPS_LOCK);
    SET_GLOBAL_CONSTANT(KEY_SCROLL_LOCK);
    SET_GLOBAL_CONSTANT(KEY_NUM_LOCK);
    SET_GLOBAL_CONSTANT(KEY_PRINT_SCREEN);
    SET_GLOBAL_CONSTANT(KEY_PAUSE);
    SET_GLOBAL_CONSTANT(KEY_F1);
    SET_GLOBAL_CONSTANT(KEY_F2);
    SET_GLOBAL_CONSTANT(KEY_F3);
    SET_GLOBAL_CONSTANT(KEY_F4);
    SET_GLOBAL_CONSTANT(KEY_F5);
    SET_GLOBAL_CONSTANT(KEY_F6);
    SET_GLOBAL_CONSTANT(KEY_F7);
    SET_GLOBAL_CONSTANT(KEY_F8);
    SET_GLOBAL_CONSTANT(KEY_F9);
    SET_GLOBAL_CONSTANT(KEY_F10);
    SET_GLOBAL_CONSTANT(KEY_F11);
    SET_GLOBAL_CONSTANT(KEY_F12);
    SET_GLOBAL_CONSTANT(KEY_LEFT_SHIFT);
    SET_GLOBAL_CONSTANT(KEY_LEFT_CONTROL);
    SET_GLOBAL_CONSTANT(KEY_LEFT_ALT);
    SET_GLOBAL_CONSTANT(KEY_LEFT_SUPER);
    SET_GLOBAL_CONSTANT(KEY_RIGHT_SHIFT);
    SET_GLOBAL_CONSTANT(KEY_RIGHT_CONTROL);
    SET_GLOBAL_CONSTANT(KEY_RIGHT_ALT);
    SET_GLOBAL_CONSTANT(KEY_RIGHT_SUPER);
    SET_GLOBAL_CONSTANT(KEY_KB_MENU);
    SET_GLOBAL_CONSTANT(KEY_LEFT_BRACKET);
    SET_GLOBAL_CONSTANT(KEY_BACKSLASH);
    SET_GLOBAL_CONSTANT(KEY_RIGHT_BRACKET);
    SET_GLOBAL_CONSTANT(KEY_GRAVE);
    SET_GLOBAL_CONSTANT(KEY_KP_0);
    SET_GLOBAL_CONSTANT(KEY_KP_1);
    SET_GLOBAL_CONSTANT(KEY_KP_2);
    SET_GLOBAL_CONSTANT(KEY_KP_3);
    SET_GLOBAL_CONSTANT(KEY_KP_4);
    SET_GLOBAL_CONSTANT(KEY_KP_5);
    SET_GLOBAL_CONSTANT(KEY_KP_6);
    SET_GLOBAL_CONSTANT(KEY_KP_7);
    SET_GLOBAL_CONSTANT(KEY_KP_8);
    SET_GLOBAL_CONSTANT(KEY_KP_9);
    SET_GLOBAL_CONSTANT(KEY_KP_DECIMAL);
    SET_GLOBAL_CONSTANT(KEY_KP_DIVIDE);
    SET_GLOBAL_CONSTANT(KEY_KP_MULTIPLY);
    SET_GLOBAL_CONSTANT(KEY_KP_SUBTRACT);
    SET_GLOBAL_CONSTANT(KEY_KP_ADD);
    SET_GLOBAL_CONSTANT(KEY_KP_ENTER);
    SET_GLOBAL_CONSTANT(KEY_KP_EQUAL);
    SET_GLOBAL_CONSTANT(KEY_BACK);
    SET_GLOBAL_CONSTANT(KEY_MENU);
    SET_GLOBAL_CONSTANT(KEY_VOLUME_UP);
    SET_GLOBAL_CONSTANT(KEY_VOLUME_DOWN);
    SET_GLOBAL_CONSTANT(KEY_PAUSE);
    SET_GLOBAL_CONSTANT(KEY_A);
    SET_GLOBAL_CONSTANT(KEY_B);
    SET_GLOBAL_CONSTANT(KEY_C);
    SET_GLOBAL_CONSTANT(KEY_D);
    SET_GLOBAL_CONSTANT(KEY_E);
    SET_GLOBAL_CONSTANT(KEY_F);
    SET_GLOBAL_CONSTANT(KEY_G);
    SET_GLOBAL_CONSTANT(KEY_H);
    SET_GLOBAL_CONSTANT(KEY_I);
    SET_GLOBAL_CONSTANT(KEY_J);
    SET_GLOBAL_CONSTANT(KEY_K);
    SET_GLOBAL_CONSTANT(KEY_L);
    SET_GLOBAL_CONSTANT(KEY_M);
    SET_GLOBAL_CONSTANT(KEY_N);
    SET_GLOBAL_CONSTANT(KEY_O);
    SET_GLOBAL_CONSTANT(KEY_P);
    SET_GLOBAL_CONSTANT(KEY_Q);
    SET_GLOBAL_CONSTANT(KEY_R);
    SET_GLOBAL_CONSTANT(KEY_S);
    SET_GLOBAL_CONSTANT(KEY_T);
    SET_GLOBAL_CONSTANT(KEY_U);
    SET_GLOBAL_CONSTANT(KEY_V);
    SET_GLOBAL_CONSTANT(KEY_W);
    SET_GLOBAL_CONSTANT(KEY_X);
    SET_GLOBAL_CONSTANT(KEY_Y);
    SET_GLOBAL_CONSTANT(KEY_Z);
    SET_GLOBAL_CONSTANT(KEY_ZERO);
    SET_GLOBAL_CONSTANT(KEY_ONE);
    SET_GLOBAL_CONSTANT(KEY_TWO);
    SET_GLOBAL_CONSTANT(KEY_THREE);
    SET_GLOBAL_CONSTANT(KEY_FOUR);
    SET_GLOBAL_CONSTANT(KEY_FIVE);
    SET_GLOBAL_CONSTANT(KEY_SIX);
    SET_GLOBAL_CONSTANT(KEY_SEVEN);
    SET_GLOBAL_CONSTANT(KEY_EIGHT);
    SET_GLOBAL_CONSTANT(KEY_NINE);

    // Input Namespace
    sol::table input_namespace = lua.create_named_table("Input");

    // Keyboard
    input_namespace.set_function("IsKeyPressed", IsKeyPressed);
    input_namespace.set_function("IsKeyDown", IsKeyDown);
    input_namespace.set_function("IsKeyReleased", IsKeyReleased);
    input_namespace.set_function("IsKeyUp", IsKeyUp);
    input_namespace.set_function("GetKeyPressed", GetKeyPressed);
    input_namespace.set_function("GetCharPressed", GetCharPressed);
    input_namespace.set_function("SetExitKey", SetExitKey);

    // Mouse
    input_namespace.set_function("IsMouseButtonPressed", IsMouseButtonPressed);
    input_namespace.set_function("IsMouseButtonDown", IsMouseButtonDown);
    input_namespace.set_function("IsMouseButtonReleased", IsMouseButtonReleased);
    input_namespace.set_function("IsMouseButtonUp", IsMouseButtonUp);
    input_namespace.set_function("GetMouseX", GetMouseX);
    input_namespace.set_function("GetMouseY", GetMouseY);
    input_namespace.set_function("GetMousePosition", GetMousePosition);
    input_namespace.set_function("SetMousePosition", SetMousePosition);
    input_namespace.set_function("SetMouseOffset", SetMouseOffset);
    input_namespace.set_function("SetMouseScale", SetMouseScale);
    input_namespace.set_function("GetMouseWheelMove", GetMouseWheelMove);
    input_namespace.set_function("SetMouseCursor", SetMouseCursor);
    input_namespace.set_function("ShowCursor", ShowCursor);
    input_namespace.set_function("HideCursor", HideCursor);
    input_namespace.set_function("IsCursorHidden", IsCursorHidden);
    input_namespace.set_function("EnableCursor", EnableCursor); 
    input_namespace.set_function("DisableCursor", DisableCursor);
    input_namespace.set_function("GetMouseRay", GetMouseRay);

    // Gamepad
    input_namespace.set_function("IsGamepadAvailable", IsGamepadAvailable);
    input_namespace.set_function("GetGamepadName", GetGamepadName);
    input_namespace.set_function("IsGamepadButtonPressed", IsGamepadButtonPressed);
    input_namespace.set_function("IsGamepadButtonDown", IsGamepadButtonDown);
    input_namespace.set_function("IsGamepadButtonReleased", IsGamepadButtonReleased);
    input_namespace.set_function("IsGamepadButtonUp", IsGamepadButtonUp);
    input_namespace.set_function("GetGamepadButtonPressed", GetGamepadButtonPressed);
    input_namespace.set_function("GetGamepadAxisCount", GetGamepadAxisCount);
    input_namespace.set_function("GetGamepadAxisMovement", GetGamepadAxisMovement);
    input_namespace.set_function("SetGamepadMappings", SetGamepadMappings);

    // Touch
    input_namespace.set_function("GetTouchX", GetTouchX);
    input_namespace.set_function("GetTouchY", GetTouchY);
    input_namespace.set_function("GetTouchPosition", GetTouchPosition);
    input_namespace.set_function("GetTouchPointId", GetTouchPointId);
    input_namespace.set_function("GetTouchPointCount", GetTouchPointCount);

    // Gestures
    input_namespace.set_function("SetGesturesEnabled", SetGesturesEnabled);
    input_namespace.set_function("IsGestureDetected", IsGestureDetected);
    input_namespace.set_function("GetGestureDetected", GetGestureDetected);
    input_namespace.set_function("GetGestureHoldDuration", GetGestureHoldDuration);
    input_namespace.set_function("GetGestureDragVector", GetGestureDragVector);
    input_namespace.set_function("GetGestureDragAngle", GetGestureDragAngle);

}