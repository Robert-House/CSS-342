//=================================================================================
// File: Album.h
// Author: Robert House 2014
//
// This object models an old record album. The properties that are exposed
// are as follows:
//					Read Speed
//					Album Side
//					Album Name
//					Number of Tracks
//					Total Album Length
//					Current Track Name (and overloaded function to get any name)
//
// Note: I did not include Track.h, but assume it exposes a track object that has
//		 a name, data, and length.
//================================================================================

#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <vector>

#include "Track.h"

class Album
{
	// Enum holding 3 common record speeds
	enum ReadSpeed
	{
		RPM33,
		RPM45,
		RPM78,
	};
	
	// Enum for album side. Default is side A
	enum AlbumSide
	{
		A,
		B,
	};

public:
	Album();
	Album(std::string name);
	~Album();

	// Getters
	std::string				getAlbumName()					const; 	// Return the album name
	double					getAlbumLength()				const; 	// Return the total album length
	AlbumSide				getAlbumSide()					const;	// Returns the current album side
	unsigned int			getNumberOfTracks()				const; 	// Return total number of tracks
	unsigned int			getCurrentTrackNum()			const; 	// Return current track number
	ReadSpeed				getReadSpeed()					const;	// Return read speed
	Track					getTrack();						const; 	// Get current track
	Track					getTrack(int TrackNumber)   	const; 	// Get specific track
	std::string				getTrackName()					const; 	// Get current track name
	std::string				getTrackName(int TrackNumber)	const; 	// Get specific track name

private:
	// Fields: Default values are given here. I do this so EVERY field gets instantiated even if
	//			some constructors are not called. If this is not best practice, I would like to know!
	double					pAlbumLength		= 0.0f;
	unsigned int			pNumberOfTracks		= 0;
	unsigned int			pCurrentTrack		= 0;
	std::string				pAlbumName			= "Untitled Album";
	ReadSpeed				pReadSpeed			= RPM33;
	AlbumSide				pAlbumSide			= A;

	std::vector <Track>		pTrackList;
};

#endif