// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaObject.h"

/**
 * 
 */
class QUE4GAME_API CppAPIUtils
{
public:
	CppAPIUtils();
	~CppAPIUtils();

	//instance
	static slua::LuaOwnedPtr<CppAPIUtils> Create();

	//Loader
	static UObject* LoadObject(const FString& fileName);
	static UClass* LoadClass(const FString& fileName);
	
	//Transform
	static void SetRelativeLocation(USceneComponent *c, FVector newLocation);
	static void SetRelativeRotation(USceneComponent *c, FRotator newRotation);
	static void SetRelativeScale3D(USceneComponent *c, FVector newScale3D);
	static void SetRelativeTransform(USceneComponent *c, const FTransform& newTransform);
	static void RegisterComponentWithWorld(USceneComponent *c, UWorld *world);
};
