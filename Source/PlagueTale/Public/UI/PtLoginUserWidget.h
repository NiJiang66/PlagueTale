// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"

#include "PtLoginUserWidget.generated.h"

class UCircularThrobber;
class UButton;
class UEditableTextBox;


/**
 * ��Ϸ��¼����
 */
UCLASS()
class PLAGUETALE_API UPtLoginUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** �ؼ�������ɵĳ�ʼ������ */
	virtual bool Initialize() override;

	/** ��¼��ť����¼�������ʹ��2020.3.12 */
	UFUNCTION()
	void OnLoginBtnOnClicked();

	/** �û���¼�ķ���������ʹ��2020.3.12 */
	void AccountLoginFromServer(FString Nickname, FString Password);
	/** �������Ӧ����������ʹ��2020.3.12 */
	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
	
public:
	/** ���ذ�ť */
	UPROPERTY()
	UButton* BackBtn;

	/** �ǳ������ */
	UPROPERTY()
	UEditableTextBox* NicknameInput;

	/** ��������� */
	UPROPERTY()
	UEditableTextBox* PasswordInput;

	/** ��¼��ť */
	UPROPERTY()
	UButton* LoginBtn;

	/** ������ */
	UPROPERTY()
	UCircularThrobber* CircularThrobber;

	/** ��Ϣ��ʾ�� */
	UPROPERTY()
	class UPtMessageUserWidget* MessageUserWidget;

};
