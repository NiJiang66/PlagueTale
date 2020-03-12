// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PtStartHUD.generated.h"

/**
 * ��ʼHUD
 */
UCLASS()
class PLAGUETALE_API APtStartHUD : public AHUD
{
	GENERATED_BODY()

public:

	APtStartHUD();

	virtual void BeginPlay() override;

	/** ��ʼ��Ϸ��ť����¼� */
	UFUNCTION()
	void StartBtnOnClickedEvent();

	/** ע���˺Ű�ť����¼� */
	UFUNCTION()
	void RegisterBtnOnClickedEvent();

	/** ��¼ҳ�淵�ذ�ť����¼� */
	UFUNCTION()
	void LoginBackBtnOnClickedEvent();

	/** ע��ҳ�淵�ذ�ť����¼� */
	UFUNCTION()
	void RegisterBackBtnOnClickedEvent();

public:

	/** ��Ϸ��ʼ���� */
	UPROPERTY()
	class UPtStartUserWidget* StartWidget;

	/** ��Ϸ��¼���� */
	UPROPERTY()
	class UPtLoginUserWidget* LoginWidget;

	/** ��Ϸע����� */
	UPROPERTY()
	class UPtRegisterUserWidget* RegisterWidget;



};
