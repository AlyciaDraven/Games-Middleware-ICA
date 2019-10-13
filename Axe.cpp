// Fill out your copyright notice in the Description page of Project Settings.

#include "Axe.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"

// Sets default values
AAxe::AAxe()
{
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	MyBoxComponent->InitBoxExtent(FVector(6.0f, 20.0f, 25.0f));
	RootComponent = MyBoxComponent;

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AAxe::OnOverlapBegin);
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &AAxe::OnOverlapEnd);

	bCanApplyDamage = false;
}

void AAxe::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bCanApplyDamage = true;
		MyCharacter = Cast<AActor>(OtherActor);
		MyHit = SweepResult;
		GetWorldTimerManager().SetTimer(MeleeTimerHandle, this, &AAxe::ApplyMeleeDamage, 2.2f, true, 0.0f);
	}
}

void AAxe::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bCanApplyDamage = false;
	GetWorldTimerManager().ClearTimer(MeleeTimerHandle);
}

void AAxe::ApplyMeleeDamage()
{
	if (bCanApplyDamage)
	{
		UGameplayStatics::ApplyPointDamage(MyCharacter, 200.0f, GetActorLocation(), MyHit, nullptr, this, MeleeDamageType);
	}
}