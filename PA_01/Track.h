#pragma once
#include <string>
using namespace std;
class Song
{
public:
	Song() // Default Track ctor
	{
		artist = "Toto";
		title = "Africa"; // It was this or Dancing Queen
	}
	Song(string a, string t) // Normal Track ctor
	{
		artist = a;
		title = t;
	}

	string getTitle() const // Returns Track title
	{
		return title;
	}
	string getArtist() const // Returns Track artist
	{
		return artist;
	}
	void print(ostream & out = cout) const
	{
		out << getTitle() << " by " << getArtist();
	}

	/*
	If Song One's Artist < Song Two's artist, then Song One < Song Two
	However, if they share an artist, then the titles are checked
	Finally, if Song Two's Artist < Song One's artist, then Song Two < Song One
	*/
	// This function isn't actually used, as I was implementing pivot which utilized a <= instead of <
	bool operator< (const Song & sng) const
	{
		if (this->getArtist() < sng.getArtist())
		{
			return this < &sng;
		}
		else if (this->getArtist() == sng.getArtist())
		{
			if (this->getTitle() < sng.getTitle())
			{
				return this < &sng;
			}
			else
			{
				return &sng < this;
			}
		}
		else
		{
			return &sng < this;
		}
	}

	// required overload for partition() function in main.cpp
	/*
		I'll hopefully remember to ask about this, but it seems wrong? I had all of these returns reversed (flipping &sng and this in all conditions)
		but it would sort my array in reverse order. Flipping the returns made it sort as I wanted it to, so I'm not sure exactly what was going on here.
	*/
	bool operator<= (const Song & sng) const
	{
		if (this->getArtist() < sng.getArtist())
		{
			return &sng < this;
		}
		else if (this->getArtist() == sng.getArtist())
		{
			if (this->getTitle() < sng.getTitle())
			{
				return &sng < this;
			}
			else
			{
				return this < &sng;
			}
		}
		else
		{
			return this < &sng;
		}
	}
private:
	string artist, title;
};

ostream & operator << (ostream & out, const Song & sng)
{
	sng.print(out);
	return out;
}