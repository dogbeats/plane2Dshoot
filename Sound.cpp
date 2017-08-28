#include "Sound.h"
#include <stdio.h>
#include <irrKlang.h>
#include <iostream>
#include <ik_ISoundSource.h>
// include console I/O methods (conio.h for windows, our wrapper in linux)

#include <conio.h>




// Also, we tell the compiler to use the namespaces 'irrklang'.
// All classes and functions of irrKlang can be found in the namespace 'irrklang'.
// If you want to use a class of the engine,
// you'll have to type an irrklang:: before the name of the class.
// For example, to use the ISoundEngine, write: irrklang::ISoundEngine. To avoid having
// to put irrklang:: before of the name of every class, we tell the compiler that
// we use that namespaces here.

using namespace irrklang;

// To be able to use the irrKlang.dll file, we need to link with the irrKlang.lib.
// We could set this option in the project settings, but to make it easy we use
// a pragma comment:

#pragma comment(lib, "test.lib") // link with irrKlang.dll


/*
void Sound::loadSound()
{
	char test = mciSendString("open \"gun.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
}
*/
ISoundEngine* engine = createIrrKlangDevice();
ISoundSource* shootSound = engine->addSoundSourceFromFile("gun2.wav");
ISoundSource* explosionSound = engine->addSoundSourceFromFile("explosion3.mp3");
//ISound* snd = engine->play2D(shootSound);

float explosionTime = 0.0f;

void Sound::InitSound()
{
	//engine[0] = createIrrKlangDevice();
	//engine[0]->play2D("gun2.wav", ESM_NO_STREAMING);
	//engine->irrklang::ISoundEngine::addSoundSourceFromFile("gun2.wav", ESM_AUTO_DETECT, true);
	
}

void Sound::DropSound()
{
	//if (snd->isFinished() == true)
	//	snd->drop();
	//engine->drop();
}

int Sound::PlaySoundN(int soundNumber, float deltaTime)
{
	// start the sound engine with default parameters

	if (!engine)
	{
		return 0;
	}

	if (soundNumber == 2)
		engine->play2D(explosionSound);
	

	// To play a sound, we only to call play2D(). The second parameter
	// tells the engine to play it looped.
	
	// play some sound stream, looped
	//engine->play2D("gun2.wav");
	//snd = engine->play2D(shootSound);
	if (soundNumber == 1)
		engine->play2D(shootSound);

//	std::cout << snd->getPlayPosition() << "\n";
	
	// In a loop, wait until user presses 'q' to exit or another key to
	// play another sound.

	// After we are finished, we have to delete the irrKlang Device created earlier
	// with createIrrKlangDevice(). Use ::drop() to do that. In irrKlang, you should
	// delete all objects you created with a method or function that starts with 'create'.
	// (an exception is the play2D()- or play3D()-method, see the documentation or the
	// next example for an explanation)
	// The object is deleted simply by calling ->drop().
	
	//engine->drop();
	return 0;
	
}