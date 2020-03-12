// Fill out your copyright notice in the Description page of Project Settings.


#include "PtPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

APtPlayerCharacter::APtPlayerCharacter()
{
	/** ���ý�ɫ�ƶ��ĳ��� */
	GetCharacterMovement()->bOrientRotationToMovement = true;
	/** ���ý�ɫ�������Ƿ���Ƴ��� */
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	/** ��ʼ�������� */
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CamerComponent");
	/** �������󶨸���� */
	CameraComponent->SetupAttachment(RootComponent);
	/** �����ɫ���������Ƴ��� */
	CameraComponent->bUsePawnControlRotation = false;
}
