// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PtStartController.generated.h"

/**
 * ��ʼ������(��¼��ѡ���ɫ����)
 */
UCLASS()
class PLAGUETALE_API APtStartController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

};
