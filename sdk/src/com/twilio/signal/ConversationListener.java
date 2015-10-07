package com.twilio.signal;

public interface ConversationListener {

	/**
	 * 
	 */
	void onConnectParticipant(Conversation conversation, Participant participant);
	
	/**
	 * 
	 */
	void onFailToConnectParticipant(Conversation conversation, Participant participant, ConversationException e);
	
	
	/**
	 * 
	 */
	void onDisconnectParticipant(Conversation conversation, Participant participant);
	
	
	/**
	 * 
	 */
	void onVideoAddedForParticipant(Conversation conversation, Participant participant, VideoTrack videoTrack);
	
	/**
	 * 
	 */
	void onVideoRemovedForParticipant(Conversation conversation, Participant participant, VideoTrack videoTrack);


	/**
	 * 
	 */
	void onLocalStatusChanged(Conversation conversation, Conversation.Status status);
	
	/**
	 * 
	 */
	void onConversationEnded(Conversation conversation);
	
	/**
	 * 
	 */
	void onConversationEnded(Conversation conversation, int error, String errorMessage);

}
