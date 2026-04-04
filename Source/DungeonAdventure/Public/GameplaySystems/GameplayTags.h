#pragma once

#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"

namespace FDAGameplayTags
{
	namespace State
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Moving);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Running);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Falling);
	}

	namespace Ability
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Interact);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Use);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Take);
	}
	
	namespace Effect
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Burn);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Poison);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Bleed);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Stun);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Slow);
	}

	namespace Event
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(RecievedDamage);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Stunned);
	}
	
	namespace Status
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Burning);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Poisoned);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Bleeding);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Stunned);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Slowed);
	}
		
	namespace Cue
	{
		
	}

	namespace Data
	{
		
	}
}