// Copyright (c) 2021 LootLocker

#include "GameAPI/LootLockerFriendsRequestHandler.h"
#include "LootLockerGameEndpoints.h"
#include "LootLockerPlatformManager.h"
#include "Utils/LootLockerUtilities.h"

ULootLockerHttpClient* ULootLockerFriendsRequestHandler::HttpClient = nullptr;

ULootLockerFriendsRequestHandler::ULootLockerFriendsRequestHandler()
{
	HttpClient = NewObject<ULootLockerHttpClient>();
}

void ULootLockerFriendsRequestHandler::GetFriendsList(const FPFriendsListResponseBP& OnCompletedRequestBP, const FFriendsListResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerFriendsListResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::GetFriendsListEndpoint, {},EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::SendFriendRequest(const FString& PlayerPublicUID, const FPSendFriendRequestResponseBP& OnCompletedRequestBP , const FSendFriendRequestResponse& OnCompletedRequest )
{
	LLAPI<FLootLockerResponse>::CallAPI(HttpClient, FLootLockerSendFriendRequest{ PlayerPublicUID }, ULootLockerGameEndpoints::SendFriendRequestEndpoint, { },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::ListIncomingFriendRequests(const FPListIncomingFriendRequestsResponseBP& OnCompletedRequestBP, const FListIncomingFriendRequestsResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerListIncomingFriendRequestsResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::ListIncomingFriendRequestsEndpoint, { },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::ListOutgoingFriendRequests(const FPListOutgoingFriendRequestsResponseBP& OnCompletedRequestBP, const FListOutgoingFriendRequestsResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerListOutgoingFriendRequestsResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::ListOutgoingFriendRequestsEndpoint, { },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::AcceptFriendRequest(const FString& PlayerID, const FPAcceptFriendRequestResponseBP& OnCompletedRequestBP, const FAcceptFriendRequestResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::AcceptFriendRequestEndpoint, { PlayerID },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::DeclineFriendRequest(const FString& PlayerID,const FPDeclineFriendRequestResponseBP& OnCompletedRequestBP,const FDeclineFriendRequestResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::DeclineFriendRequestEndpoint, { PlayerID },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::DeleteFriend(const FString& PlayerID, const FPDeleteFriendResponseBP& OnCompletedRequestBP, const FDeleteFriendResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::DeleteFriendEndpoint, { PlayerID },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::ListBlockedPlayers(const FPListBlockedPlayersResponseBP& OnCompletedRequestBP, const FListBlockedPlayersResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerListBlockedPlayersResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::ListBlockedPlayersEndpoint, {},EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::BlockPlayer(const FString& PlayerID, const FPBlockPlayerResponseBP& OnCompletedRequestBP, const FBlockPlayerResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::BlockPlayerEndpoint, { PlayerID },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerFriendsRequestHandler::UnblockPlayer(const FString& PlayerID, const FPUnblockPlayerResponseBP& OnCompletedRequestBP, const FUnblockPlayerResponse& OnCompletedRequest)
{
	LLAPI<FLootLockerResponse>::CallAPI(HttpClient, LootLockerEmptyRequest, ULootLockerGameEndpoints::UnblockPlayerEndpoint, { PlayerID },EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}
