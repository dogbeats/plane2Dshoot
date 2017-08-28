#ifndef SOUND_H
#define SOUND_H

class Sound
{
	public:
		int PlaySoundN(int soundNumber, float deltaTime);
		void InitSound();
		void DropSound();
};

#endif 