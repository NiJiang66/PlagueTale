// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PtStartUserWidget.generated.h"

class UButton;
class UTextBlock;

/**
 * ��Ϸ��ʼ����
 */
UCLASS()
class PLAGUETALE_API UPtStartUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/** ��д�ؼ�������ɺ��ʼ������ */
	virtual bool Initialize() override;

	/** �˳���Ϸ��ť����¼� */
	UFUNCTION()
	void QuitBtnOnClickedEvent();
	
public:

	/** ��ʼ��Ϸ��ť */
	UPROPERTY()
	UButton* StartBtn;

	/** ע���˺Ű�ť */
	UPROPERTY()
	UButton* RegisterBtn;

	/** �˳���Ϸ��ť */
	UPROPERTY()
	UButton* QuitBtn;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* clientVersionLabel;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* clientScriptVersionLabel;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* serverVerstionLabel;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* serverScriptVersionLabel;

};
