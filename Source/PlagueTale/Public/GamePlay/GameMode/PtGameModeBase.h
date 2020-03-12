// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//#include "Scripts/PtEventData.h"
#include "PtGameModeBase.generated.h"

class UKBEventData;

/**
 * ��Ϸģʽ����
 */
UCLASS()
class PLAGUETALE_API APtGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	APtGameModeBase();

	/** Called once this actor has been deleted */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;

	/**	��װ��½ʱ��Ҫ������KBE�¼� */
	virtual void InstallEvents();
	/**	ע�����볡��ʱע���KBE�¼� */
	virtual void UnInstallEvents();

	/**	KBE�¼�,��ұ��߳������� */
	virtual void OnKicked(const UKBEventData* pEventData);
	/**	KBE�¼�,����ʱ */
	virtual void OnDisconnected(const UKBEventData* pEventData);
	/**	KBE�¼�,��ǰ����״̬ */
	virtual void OnConnectionState(const UKBEventData* pEventData);
	/**	KBE�¼�,�������� */
	virtual void OnReloginBaseappSuccessfully(const UKBEventData* pEventData);
	/**	KBE�¼�,����ʧ�� */
	virtual void OnReloginBaseappFailed(const UKBEventData* pEventData);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**	��ʼ���µ�¼Baseapp������Loginapp����Ϊ��¼֮��������ת�Ƶ�Baseapp */
	void StartReloginBaseappTimer();
	/**	ֹͣ���µ�¼Baseapp */
	void StopReloginBaseappTimer();

	/**	�ص�baseapp��Ŀ���󶨸���ʱ�����¼� */
	void OnReloginBaseappTimer();


protected:

	/**	��ʱ�� */
	FTimerHandle TimerHandle;

	bool StartRelogin;

};
