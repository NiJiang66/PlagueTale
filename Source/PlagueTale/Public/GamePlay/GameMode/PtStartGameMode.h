// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PtGameModeBase.h"
#include "PtStartGameMode.generated.h"

class UKBEMain;

/**
 * ��ʼ��Ϸģʽ(��¼����)
 */
UCLASS()
class PLAGUETALE_API APtStartGameMode : public APtGameModeBase
{
	GENERATED_BODY()
	
public:

	APtStartGameMode();

	/**	��װ��½ʱ��Ҫ������KBE�¼� */
	virtual void InstallEvents();

	/**	KBE�¼�  */
	void OnCreateAccountResult(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void OnLoginFailed(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void OnVersionNotMatch(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void OnScriptVersionNotMatch(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void OnLoginBaseappFailed(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void OnLoginSuccessfully(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void OnLoginBaseapp(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void Loginapp_importClientMessages(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void Baseapp_importClientMessages(const UKBEventData* pEventData);
	/**	KBE�¼�  */
	void Baseapp_importClientEntityDef(const UKBEventData* pEventData);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	/**	��������ģ�� */
	UKBEMain* KBEMain;
};
