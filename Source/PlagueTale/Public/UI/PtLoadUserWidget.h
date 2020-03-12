// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PtLoadUserWidget.generated.h"

/**
 * ��Ϸ���ؽ���
 */
UCLASS()
class PLAGUETALE_API UPtLoadUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/** �ؼ�������ɳ�ʼ������ */
	virtual bool Initialize() override;

	/** ��дTick */
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime)override;

	/** ���ÿ�ʼ���� */
	void SetStartLoad();

	/** �������� */
	void SetEndLoad();
	
public:

	/** ���ؽ����� */
	UPROPERTY()
	class UCircularThrobber* CircularThrobber;

	/** �����ı� */
	UPROPERTY()
	class UTextBlock* LoadingText;

	/** ������ť */
	UPROPERTY()
	class UButton* NextButton;

private:

	/** ������Ϸʵ�� */
	class UPTGameInstance* PtGameInstance = nullptr;

};
