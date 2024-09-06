// Copyright (c) 2021 LootLocker

#pragma once

#include "CoreMinimal.h"
#include "LootLockerAssetsRequestHandler.h"
#include "LootLockerHttpClient.h"
#include "LootLockerResponse.h"
#include "LootLockerFriendsRequestHandler.generated.h"

USTRUCT(BlueprintType, Category="LootLocker")
struct FLootLockerSendFriendRequest
{
	GENERATED_BODY()
	/**
	 * Player to befriend.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString player_public_uid;
};



USTRUCT(BlueprintType)
struct FLootLockerFriendsListArray
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString player_id;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString public_uid;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FDateTime accepted_at;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	bool online = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FDateTime created_at;
};

USTRUCT(BlueprintType)
struct FLootLockerFriendsListResponse : public FLootLockerResponse
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerFriendsListArray> friends;
};

USTRUCT(BlueprintType)
struct FLootLockerListIncomingFriendRequestResponseArray
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString player_id;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString public_uid;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FDateTime accepted_at;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FDateTime created_at;
};

USTRUCT(BlueprintType)
struct FLootLockerListIncomingFriendRequestsResponse : public FLootLockerResponse
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerListIncomingFriendRequestResponseArray> incoming;
};

USTRUCT(BlueprintType)
struct FLootLockerListOutgoingFriendRequestResponseArray
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString player_id;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString public_uid;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FDateTime accepted_at;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	bool online = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FDateTime created_at;
};

USTRUCT(BlueprintType)
struct FLootLockerListOutgoingFriendRequestsResponse : public FLootLockerResponse
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerListOutgoingFriendRequestResponseArray> outgoing;
};

USTRUCT(BlueprintType)
struct FLootLockerListBlockedPlayersResponseArray
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString player_id;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString public_uid;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FDateTime blocked_at;
};

USTRUCT(BlueprintType)
struct FLootLockerListBlockedPlayersResponse : public FLootLockerResponse
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerListBlockedPlayersResponseArray> blocked;
};


DECLARE_DYNAMIC_DELEGATE_OneParam(FPFriendsListResponseBP, FLootLockerFriendsListResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPSendFriendRequestResponseBP, FLootLockerResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPListIncomingFriendRequestsResponseBP, FLootLockerListIncomingFriendRequestsResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPListOutgoingFriendRequestsResponseBP, FLootLockerListOutgoingFriendRequestsResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPAcceptFriendRequestResponseBP, FLootLockerResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPDeclineFriendRequestResponseBP, FLootLockerResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPDeleteFriendResponseBP, FLootLockerResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPListBlockedPlayersResponseBP, FLootLockerListBlockedPlayersResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPBlockPlayerResponseBP, FLootLockerResponse, Var);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPUnblockPlayerResponseBP, FLootLockerResponse, Var);

DECLARE_DELEGATE_OneParam(FFriendsListResponse, FLootLockerFriendsListResponse);
DECLARE_DELEGATE_OneParam(FSendFriendRequestResponse, FLootLockerResponse);
DECLARE_DELEGATE_OneParam(FListIncomingFriendRequestsResponse, FLootLockerListIncomingFriendRequestsResponse);
DECLARE_DELEGATE_OneParam(FListOutgoingFriendRequestsResponse, FLootLockerListOutgoingFriendRequestsResponse);
DECLARE_DELEGATE_OneParam(FAcceptFriendRequestResponse, FLootLockerResponse);
DECLARE_DELEGATE_OneParam(FDeclineFriendRequestResponse, FLootLockerResponse);
DECLARE_DELEGATE_OneParam(FDeleteFriendResponse, FLootLockerResponse);
DECLARE_DELEGATE_OneParam(FListBlockedPlayersResponse, FLootLockerListBlockedPlayersResponse);
DECLARE_DELEGATE_OneParam(FBlockPlayerResponse, FLootLockerResponse);
DECLARE_DELEGATE_OneParam(FUnblockPlayerResponse, FLootLockerResponse);

UCLASS()
class LOOTLOCKERSDK_API ULootLockerFriendsRequestHandler : public UObject
{
	GENERATED_BODY()
public:
	ULootLockerFriendsRequestHandler();
	static void GetFriendsList(const FPFriendsListResponseBP& OnCompleteRequestBP = FPFriendsListResponseBP(), const FFriendsListResponse& OnCompletedRequest = FFriendsListResponse());
	static void SendFriendRequest(const FString& PlayerPublicUID, const FPSendFriendRequestResponseBP& OnCompletedRequestBP = FPSendFriendRequestResponseBP(), const FSendFriendRequestResponse& OnCompletedRequest = FSendFriendRequestResponse());
	static void ListIncomingFriendRequests(const FPListIncomingFriendRequestsResponseBP& OnCompletedRequestBP = FPListIncomingFriendRequestsResponseBP(), const FListIncomingFriendRequestsResponse& OnCompletedRequest = FListIncomingFriendRequestsResponse());
	static void ListOutgoingFriendRequests(const FPListOutgoingFriendRequestsResponseBP& OnCompletedRequestBP = FPListOutgoingFriendRequestsResponseBP(), const FListOutgoingFriendRequestsResponse& OnCompletedRequest = FListOutgoingFriendRequestsResponse());
	static void AcceptFriendRequest(const FString& PlayerID, const FPAcceptFriendRequestResponseBP& OnCompletedRequestBP = FPAcceptFriendRequestResponseBP(), const FAcceptFriendRequestResponse& OnCompletedRequest = FAcceptFriendRequestResponse());
	static void DeclineFriendRequest(const FString& PlayerID, const FPDeclineFriendRequestResponseBP& OnCompletedRequestBP = FPDeclineFriendRequestResponseBP(), const FDeclineFriendRequestResponse& OnCompletedRequest = FDeclineFriendRequestResponse());
	static void DeleteFriend(const FString& PlayerID, const FPDeleteFriendResponseBP& OnCompletedRequestBP = FPDeleteFriendResponseBP(), const FDeleteFriendResponse& OnCompletedRequest = FDeleteFriendResponse());
	static void ListBlockedPlayers(const FPListBlockedPlayersResponseBP& OnCompletedRequestBP = FPListBlockedPlayersResponseBP(), const FListBlockedPlayersResponse& OnCompletedRequest = FListBlockedPlayersResponse());
	static void BlockPlayer(const FString& PlayerID, const FPBlockPlayerResponseBP& OnCompletedRequestBP = FPBlockPlayerResponseBP(), const FBlockPlayerResponse& OnCompletedRequest = FBlockPlayerResponse());
	static void UnblockPlayer(const FString& String, const FPUnblockPlayerResponseBP& OnCompletedRequestBP = FPUnblockPlayerResponseBP(), const FUnblockPlayerResponse& OnCompletedRequest = FUnblockPlayerResponse());

public:
	static ULootLockerHttpClient* HttpClient;
};


