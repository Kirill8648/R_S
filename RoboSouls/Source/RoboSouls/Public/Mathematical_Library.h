// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Mathematical_Library.generated.h"

UCLASS()
class ROBOSOULS_API UMathematical_Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintPure, Category = "MyMathLibrary")
		static FVector Rotate_Ring_Vector(FVector begin, FVector end, float distance_from_the_axis, float angle, float distance_from_the_beginning, FVector axis, FVector axisZ);
	UFUNCTION(BlueprintPure, Category = "MyMathLibrary")
		static FVector Curve_Bezier(FVector start_point, FVector end_point, FVector control_point_1, FVector control_point_2, float time);
};
