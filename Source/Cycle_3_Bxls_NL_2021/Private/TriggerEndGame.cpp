// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerEndGame.h"

// Sets default values for this component's properties
UTriggerEndGame::UTriggerEndGame()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTriggerEndGame::BeginPlay()
{
	Super::BeginPlay();
	SetupBoxCollider();
	
}


// Called every frame
void UTriggerEndGame::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTriggerEndGame::SetupBoxCollider()
{
	boxCollider = GetOwner()->FindComponentByClass<UBoxComponent>();
	if (ensure(boxCollider))
	{
		UE_LOG(LogTemp, Warning, TEXT("Box collider Component find"));
		//comme OnOverlapBegin et OnEndOverlap agissent comme des custom event dynamiques, il faut leur ajouter un AddDynamic
		boxCollider->OnComponentBeginOverlap.AddDynamic(this,&UTriggerEndGame::OnOverlapBegin);
	}
}



void UTriggerEndGame::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
										 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("EndGameTriggerActivated"));
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}
