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

FVector UMathematical_Library::Angle_3d_with_coordinate_axis(FVector vector)
{

	FVector temp_vector_1(vector.X, vector.Y, 0);
	FVector temp_vector_2(vector.X, 0, vector.Z);

	FVector coordinate_axis_1(1, 0, 0);
	FVector coordinate_axis_2(0, 1, 0);

	float cos_1 = temp_vector_1.CosineAngle2D(coordinate_axis_1);
	float cos_2 = temp_vector_2.CosineAngle2D(coordinate_axis_2);

	FVector unit_vector(1, 0, 0);

	FRotator rot(0.f, -cos_2, cos_1);

	unit_vector = rot.RotateVector(unit_vector);

	return unit_vector;
}

FVector UMathematical_Library::Get_vector_circular_trajectory(FVector begin, FVector end, float distance_from_the_axis, float distance_from_the_beginning, float time)
{
	FVector axisY = end - begin;

	FVector axisZ = Angle_3d_with_coordinate_axis(axisY);

	float lenght = sqrt(axisY.SizeSquared());
	axisY.Set(axisY.X / lenght, axisY.Y / lenght, axisY.Z / lenght);

	return Rotate_Ring_Vector(begin, end, distance_from_the_axis, time, distance_from_the_beginning, axisY, axisZ);
}
