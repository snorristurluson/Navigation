// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavModifierVolume.h"
#include "NavRelevantComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "SplineMeshBuilder.generated.h"

/**
* 
*/
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class USplineMeshBuilder : public UNavRelevantComponent
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USplineComponent* Spline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCollisionProfileName CollisionProfile = FName("BlockAll");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPhysicalMaterial* PhysicalMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UNavArea> AreaClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AddNavAreas = false;

	UFUNCTION(BlueprintCallable)
	void Rebuild();
	
	virtual void CalcAndCacheBounds() const override;

	protected:
	UPROPERTY()
	TArray<USplineMeshComponent*> SplineMeshComponents;

	UPROPERTY()
	TArray<ANavModifierVolume*> NavModifierVolumes;

	TArray<TArray<FVector>> NavAreas;
	
	void ClearCurrentMeshes();
	USplineMeshComponent* CreateMeshComponent(FVector StartPos, FVector StartTangent, FVector EndPos, FVector EndTangent);
	void AddMeshesToOwner();

	virtual void GetNavigationData(FNavigationRelevantData& Data) const override;
};
