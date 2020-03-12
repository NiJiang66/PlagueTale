// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"

#include "PtRegisterUserWidget.generated.h"

class UButton;
class UEditableTextBox;
class UCircularThrobber;
class APtStartGameMode;
class UPtMessageUserWidget;


/**
 * ��Ϸע�����
 */
UCLASS()
class PLAGUETALE_API UPtRegisterUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/** �жϿؼ������Ƿ���سɹ� */
	virtual bool Initialize() override;

	/** ע�ᰴť����¼� */
	UFUNCTION()
	void OnRegisterBtnOnClicked();

	/** �˺�ע�᷽��������ʹ��2020.3.12 */
	void AccountRegisterFromServer(FString&Nickname, FString&Password);
	/** ������Ӧ����������ʹ��2020.3.12 */
	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);

public:

	/** �������˰�ť���� */
	UPROPERTY()
	UButton* BackBtn;

	/** ����ע���˺Ű�ť���� */
	UPROPERTY()
	UButton* RegisterBtn;

	/** �����ǳ��������� */
	UPROPERTY()
	UEditableTextBox* NicknameInput;

	/** ���������������� */
	UPROPERTY()
	UEditableTextBox * PasswordInput;

	/** �����ٴ����������������� */
	UPROPERTY()
	UEditableTextBox* RePasswordInput;

	/** ����LoadingЧ�� */
	UPROPERTY()
	UCircularThrobber* CircularThrobber;

	/* ��ʼ��Message��*/
	UPROPERTY()
	UPtMessageUserWidget* MessageUserWidget;

};
