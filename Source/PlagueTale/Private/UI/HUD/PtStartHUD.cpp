// Fill out your copyright notice in the Description page of Project Settings.


#include "PtStartHUD.h"
#include "PtStartUserWidget.h"
#include "PtRegisterUserWidget.h"
#include "PtLoginUserWidget.h"
#include "Button.h"
#include "ConstructorHelpers.h"
#include "Engine/Engine.h"


APtStartHUD::APtStartHUD()
{	
	//������Ϸ��ʼWidget
	static ConstructorHelpers::FClassFinder<UPtStartUserWidget> PTStartUserWidget(
		TEXT("WidgetBlueprint'/Game/UI/PTStartUserWidget_BP.PTStartUserWidget_BP_C'")
	);
	StartWidget = CreateWidget<UPtStartUserWidget>(GetWorld(), PTStartUserWidget.Class);

	//������Ϸ��¼Widget
	static ConstructorHelpers::FClassFinder<UPtLoginUserWidget> PTLoginUserWidget(
		TEXT("WidgetBlueprint'/Game/UI/PTLoginUserWidget_BP.PTLoginUserWidget_BP_C'")
	);
	LoginWidget = CreateWidget<UPtLoginUserWidget>(GetWorld(), PTLoginUserWidget.Class);

	//����ע���˺�Widget
	static ConstructorHelpers::FClassFinder<UPtRegisterUserWidget> PTRegisterUserWidget(
		TEXT("WidgetBlueprint'/Game/UI/PTRegisterUserWidget_BP.PTRegisterUserWidget_BP_C'")
	);
	RegisterWidget = CreateWidget<UPtRegisterUserWidget>(GetWorld(), PTRegisterUserWidget.Class);

}

/** ��Ϸ��ʼ���õķ��� */
void APtStartHUD::BeginPlay()
{
	Super::BeginPlay();	
	//��ʾ����Ļ
	StartWidget->AddToViewport();

	//��ʼ��Ϸ��ť�ĵ���¼�
	StartWidget->StartBtn->OnClicked.AddDynamic(this, &APtStartHUD::StartBtnOnClickedEvent);
	//ע���˺Ű�ť�ĵ���¼�
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &APtStartHUD::RegisterBtnOnClickedEvent);

	//���õ�¼���淵�ذ�ť�ĵ���¼�
	LoginWidget->BackBtn->OnClicked.AddDynamic(this, &APtStartHUD::LoginBackBtnOnClickedEvent);

	//����ע����淵�ذ�ť�ĵ���¼�
	RegisterWidget->BackBtn->OnClicked.AddDynamic(this, &APtStartHUD::RegisterBackBtnOnClickedEvent);
}

/** ��ʼ��Ϸ��ť����¼� */
void APtStartHUD::StartBtnOnClickedEvent()
{
	//��Ϸ��ʼ������ӿ����Ƴ�
	StartWidget->RemoveFromViewport();
	//��¼��Ϸ������ӵ��ӿ�
	LoginWidget->AddToViewport();
}

/** ע���˺Ű�ť����¼� */
void APtStartHUD::RegisterBtnOnClickedEvent()
{
	//��Ϸ��ʼ������ӿ����Ƴ�
	StartWidget->RemoveFromViewport();
	//ע���˺Ž�����ӵ��ӿ���
	RegisterWidget->AddToViewport();
}

/** ��¼ҳ�淵�ذ�ť����¼� */
void APtStartHUD::LoginBackBtnOnClickedEvent()
{
	//��¼�˺Ž�����ӿ����Ƴ� 
	LoginWidget->RemoveFromViewport();
	//��Ϸ��ʼ������ӵ��ӿڵ���
	StartWidget->AddToViewport();
}

/** ע��ҳ�淵�ذ�ť����¼� */
void APtStartHUD::RegisterBackBtnOnClickedEvent()
{
	//ע���˺Ž�����ӿ����Ƴ�
	RegisterWidget->RemoveFromViewport();
	//��Ϸ��ʼ������ӵ��ӿڵ���
	StartWidget->AddToViewport();
}
