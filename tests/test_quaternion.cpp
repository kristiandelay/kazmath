#include <UnitTest++.h>
#include "../kazmath/quaternion.h"
#include "../kazmath/vec3.h"

TEST(test_quaternion_multiply_vec3) {
    kmVec3 v;
    kmVec3Fill(&v, 0, 1, 0);
    
    kmQuaternion q;
    kmQuaternionRotationPitchYawRoll(&q, 0, 0, kmDegreesToRadians(90));
    
    kmQuaternionMultiplyVec3(&v, &q, &v);
    
    kmVec3 expected;
    kmVec3Fill(&expected, 1, 0, 0);
    
    CHECK(kmVec3AreEqual(&expected, &v));
}

TEST(test_quaternion_slerp_edge_case) {
    kmQuaternion initial, dest;
    kmQuaternionFill(&initial, 0, 0, 0.230166689, 0.973177314);
    kmQuaternionFill(&dest, 0, 0, 0.233441412, 0.972370863);

    double step = 0.016666666666666666;

    kmQuaternion result;
    kmQuaternionSlerp(&result, &initial, &dest, step);

    CHECK(!isnan(result.x));
    CHECK(!isnan(result.y));
    CHECK(!isnan(result.z));
    CHECK(!isnan(result.w));
}

