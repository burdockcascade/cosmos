#include <sol/sol.hpp>
#include <raylib.h>

void bind_math(sol::state& lua) {

    // Math Namespace
    sol::table math_namespace = lua.create_named_table("Math");

    // Trigonometry
    math_namespace.set_function("Sin", [](float a) {
        return sinf(a);
    });
    math_namespace.set_function("Cos", [](float a) {
        return cosf(a);
    });
    math_namespace.set_function("Tan", [](float a) {
        return tanf(a);
    });
    math_namespace.set_function("Asin", [](float a) {
        return asinf(a);
    });
    math_namespace.set_function("Acos", [](float a) {
        return acosf(a);
    });
    math_namespace.set_function("Atan", [](float a) {
        return atanf(a);
    });
    math_namespace.set_function("Atan2", [](float a, float b) {
        return atan2f(a, b);
    });

    // Exponents
    math_namespace.set_function("Pow", [](float a, float b) {
        return powf(a, b);
    });
    math_namespace.set_function("Exp", [](float a) {
        return expf(a);
    });
    math_namespace.set_function("Log", [](float a) {
        return logf(a);
    });
    math_namespace.set_function("Log10", [](float a) {
        return log10f(a);
    });

    // Rounding
    math_namespace.set_function("Ceil", [](float a) {
        return ceilf(a);
    });
    math_namespace.set_function("Floor", [](float a) {
        return floorf(a);
    });
    math_namespace.set_function("Round", [](float a) {
        return roundf(a);
    });

    // Random
    math_namespace.set_function("GetRandomValue", [](float min, float max) {
        return GetRandomValue(min, max);
    });
    
    math_namespace.set_function("SetRandomSeed", [](int seed) {
        SetRandomSeed(seed);
    });
}