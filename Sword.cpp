// Fill out your copyright notice in the Description page of Project Settings.

#include "Sword.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"

// Sets default values
ASword::ASword()
{
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	MyBoxComponent->InitBoxExtent(FVector(5.0f, 15.0f, 45.0f));
	RootComponent = MyBoxComponent;

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASword::OnOverlapBegin);
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &ASword::OnOverlapEnd);

	bCanApplyDamage = false;
}

void ASword::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bCanApplyDamage = true;
		MyCharacter = Cast<AActor>(OtherActor);
		MyHit = SweepResult;
		GetWorldTimerManager().SetTimer(MeleeTimerHandle, this, &ASword::ApplyMeleeDamage, 2.2f, true, 0.0f);
	}
}

void ASword::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bCanApplyDamage = false;
	GetWorldTimerManager().ClearTimer(MeleeTimerHandle);
}

void ASword::ApplyMeleeDamage()
{
	if (bCanApplyDamage)
	{
		UGameplayStatics::ApplyPointDamage(MyCharacter, 200.0f, GetActorLocation(), MyHit, nullptr, this, MeleeDamageType);
	}
}