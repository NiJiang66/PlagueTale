// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PtMessageUserWidget.generated.h"

/**
 * ��ʾ��UI
 */
UCLASS()
class PLAGUETALE_API UPtMessageUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	/* ���ùرհ�ť�¼�*/
	UFUNCTION()
	void ClosButtonOnClickedEvent();
	
public:

	/* ��ʼ���ı���*/
	UPROPERTY()
	class UTextBlock* MsgBlock;

	/* ��ʼ���رհ�ť*/
	UPROPERTY()
	class UButton* CloseBtn;

};
