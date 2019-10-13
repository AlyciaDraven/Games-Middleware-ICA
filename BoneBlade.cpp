// Fill out your copyright notice in the Description page of Project Settings.

#include "BoneBlade.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"

// Sets default values
ABoneBlade::ABoneBlade()
{

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	MyBoxComponent->InitBoxExtent(FVector(3.5f, 15.0f, 50.0f));
	RootComponent = MyBoxComponent;

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABoneBlade::OnOverlapBegin);
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &ABoneBlade::OnOverlapEnd);

	bCanApplyDamage = false;
}

void ABoneBlade::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bCanApplyDamage = true;
		MyCharacter = Cast<AActor>(OtherActor);
		MyHit = SweepResult;
		GetWorldTimerManager().SetTimer(MeleeTimerHandle, this, &ABoneBlade::ApplyMeleeDamage, 2.2f, true, 0.0f);
	}
}

void ABoneBlade::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bCanApplyDamage = false;
	GetWorldTimerManager().ClearTimer(MeleeTimerHandle);
}

void ABoneBlade::ApplyMeleeDamage()
{
	if (bCanApplyDamage)
	{
		UGameplayStatics::ApplyPointDamage(MyCharacter, 50.0f, GetActorLocation(), MyHit, nullptr, this, MeleeDamageType);
	}
}