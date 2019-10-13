// Fill out your copyright notice in the Description page of Project Settings.

#include "Fire.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"


// Sets default values
AFire::AFire()
{

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	MyBoxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = MyBoxComponent;

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AFire::OnOverlapBegin);
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &AFire::OnOverlapEnd);

	bCanApplyDamage = false;
}

void AFire::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bCanApplyDamage = true;
		MyCharacter = Cast<AActor>(OtherActor);
		MyHit = SweepResult;
		GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AFire::ApplyFireDamage, 2.2f, true, 0.0f);
	}
}

void AFire::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bCanApplyDamage = false;
	GetWorldTimerManager().ClearTimer(FireTimerHandle);
}

void AFire::ApplyFireDamage()
{
	if (bCanApplyDamage)
	{
		UGameplayStatics::ApplyPointDamage(MyCharacter, 200.0f, GetActorLocation(), MyHit, nullptr, this, FireDamageType);
	}
}