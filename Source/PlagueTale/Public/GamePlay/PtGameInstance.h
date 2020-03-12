// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PTGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PLAGUETALE_API UPTGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/** ��ʼ������ */
	virtual void Init() override;
	/** ��ͼ���ؿ�ʼ�ķ��� */
	UFUNCTION()
		void PreLoadMap(const FString& Map);
	/** ��ͼ���ؽ����ķ��� */
	UFUNCTION()
		void PostLoadMap(UWorld* World);
	/** �Ƿ������� */
	UFUNCTION(BlueprintCallable, Category = LoadFunction)
		bool GetLoadStatus();

public:
	/** �洢���ݼ��� */
	TMap<FString, FString> ContextMap;
	/** ���ص�UI */
	UPROPERTY()
	class UPtLoadUserWidget* LoadWidget;

};
