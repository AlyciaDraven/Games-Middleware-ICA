// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sword.generated.h"


UCLASS()
class ISLAND_API ASword : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASword();

	UPROPERTY(EditAnywhere)
	class UBoxComponent* MyBoxComponent;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UDamageType> MeleeDamageType;

	UPROPERTY(EditAnywhere)
		AActor* MyCharacter;

	UPROPERTY(EditAnywhere)
		FHitResult MyHit;

	bool bCanApplyDamage;
		FTimerHandle MeleeTimerHandle;

	// declare component overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare component overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void ApplyMeleeDamage();
	
};
