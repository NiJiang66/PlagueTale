// Fill out your copyright notice in the Description page of Project Settings.


#include "PtGameInstance.h"
#include "MoviePlayer/Public/MoviePlayer.h"
#include "ConstructorHelpers.h"
#include "PtLoadUserWidget.h"

#include "CircularThrobber.h"
#include "TextBlock.h"
#include "Button.h"


/** ��ʼ������ */
void UPTGameInstance::Init()
{
	UGameInstance::Init();

	//��ʼ���ص�ͼ��ί��
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UPTGameInstance::PreLoadMap);
	//�������ص�ͼ��ί��
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UPTGameInstance::PostLoadMap);

	//��ʼ������Widget
	LoadWidget = CreateWidget<UPtLoadUserWidget>(this, LoadClass<UPtLoadUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/PTLoadUserWidget_BP.PTLoadUserWidget_BP_C'")));
}

/** ��ͼ���ؿ�ʼ�ķ��� */
void UPTGameInstance::PreLoadMap(const FString& Map)
{
	//�ж��Ƿ��Ǽ��ص����ؿ�//��ʱ���عؿ���Ҫ��ʾload����
	//if (Map.Equals("/Game/Map/Map_Main"))
	{
		//����һ����Ļ�������Զ���
		FLoadingScreenAttributes LoadingAttr;
		//�ֶ��ĵ����������
		LoadingAttr.bWaitForManualStop = true;
		//���ü��ص�Widget
		LoadingAttr.WidgetLoadingScreen = LoadWidget->TakeWidget();
		//���ÿ�ʼ����
		LoadWidget->SetStartLoad();
		//���ü�����Ļ
		GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);
	}
}

/** ��ͼ���ؽ����ķ��� */
void UPTGameInstance::PostLoadMap(UWorld* World)
{
}

/** �Ƿ������� */
bool UPTGameInstance::GetLoadStatus()
{
	//�����Ƿ��Ѿ��������
	return GetMoviePlayer()->IsLoadingFinished();
}

