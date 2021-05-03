#include "Mathematical_Library.h"

FVector UMathematical_Library::Rotate_Ring_Vector(FVector begin, FVector end, float distance_from_the_axis, float angle, float distance_from_the_beginning, FVector axis, FVector axisZ)
{
	FVector temp = end - begin;

	FVector temp_left = temp;

	float lenght = sqrt(temp_left.SizeSquared());
	temp_left.Set(temp_left.X / lenght, temp_left.Y / lenght, temp_left.Z / lenght);
	FVector temp_final = temp_left * distance_from_the_axis;

	temp_final = temp_final.RotateAngleAxis(90, axisZ);
	temp_final = temp_final.RotateAngleAxis(angle, axis);

	FVector C = FMath::Lerp(begin, end, distance_from_the_beginning);

	temp_final += C;

	return temp_final;
}

FVector UMathematical_Library::Curve_Bezier(FVector start_point, FVector end_point, FVector control_point_1, FVector control_point_2, float time)
{
	float one_minus_time = 1 - time;

	FVector final_point(start_point * one_minus_time * one_minus_time * one_minus_time + control_point_1 * 3 * one_minus_time * one_minus_time * time
		+ control_point_2 * 3 * one_minus_time * time * time + end_point * time * time * time);

	return final_point;
}
