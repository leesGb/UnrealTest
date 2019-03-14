// Fill out your copyright notice in the Description page of Project Settings.

#include "CppAPIUtils.h"
#include "UObject/UObjectGlobals.h"

using namespace slua;

CppAPIUtils::CppAPIUtils()
{
}

CppAPIUtils::~CppAPIUtils()
{
}

LuaOwnedPtr<CppAPIUtils> CppAPIUtils::Create()
{
	return new CppAPIUtils();
}

UObject* CppAPIUtils::LoadObject(const FString& fileName)
{
	return LoadObject<UObject>(nullptr, *fileName);
}

UClass* CppAPIUtils::LoadClass(const FString& fileName)
{
	return LoadClass<UClass>(nullptr, *fileName);
}

void CppAPIUtils::SetRelativeLocation(USceneComponent *c, FVector newLocation)
{
	if (c != nullptr)
	{
		c->SetRelativeLocation(newLocation);
	}
}

void CppAPIUtils::SetRelativeRotation(USceneComponent *c, FRotator newRotation)
{
	if (c != nullptr)
	{
		c->SetRelativeRotation(newRotation);
	}
}

void CppAPIUtils::SetRelativeScale3D(USceneComponent *c, FVector newScale3D)
{
	if (c != nullptr)
	{
		c->SetRelativeScale3D(newScale3D);
	}
}

void CppAPIUtils::SetRelativeTransform(USceneComponent *c, const FTransform& newTransform)
{
	if (c != nullptr)
	{
		c->SetRelativeTransform(newTransform);
	}
}

void CppAPIUtils::RegisterComponentWithWorld(USceneComponent *c, UWorld *world)
{
	if (c != nullptr && world != nullptr)
	{
		c->RegisterComponentWithWorld(world);
	}
}


DefLuaClass(CppAPIUtils)
	//Loader
	DefLuaMethod(LoadObject, &CppAPIUtils::LoadObject)
	DefLuaMethod(LoadClass, &CppAPIUtils::LoadClass)
	//Transform
	DefLuaMethod(SetRelativeLocation, &CppAPIUtils::SetRelativeLocation)
	DefLuaMethod(SetRelativeRotation, &CppAPIUtils::SetRelativeRotation)
	DefLuaMethod(SetRelativeScale3D, &CppAPIUtils::SetRelativeScale3D)
	DefLuaMethod(SetRelativeTransform, &CppAPIUtils::SetRelativeTransform)
	DefLuaMethod(RegisterComponentWithWorld, &CppAPIUtils::RegisterComponentWithWorld)
EndDef(CppAPIUtils, &CppAPIUtils::Create)
