/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef BACKENDS_MIXER_NULL_H
#define BACKENDS_MIXER_NULL_H

#include "backends/mixer/mixer.h"

/** Audio mixer which in fact does not output audio.
 *
 *  It is used by events recorder since the recorder is intentionally
 *  turning sound off to avoid stuttering.
 *
 *  It returns correct output and shoots callbacks, so all OSystem
 *  users could work without modifications.
 */

class NullMixerManager : public MixerManager {
public:
	NullMixerManager();
	virtual ~NullMixerManager();

	void init();
	void update(uint8 callbackPeriod = 10);

	void suspendAudio() override;
	int resumeAudio() override;

	bool isNullDevice() const override;

private:
	uint32 _outputRate;
	uint32 _callsCounter;
	uint32 _samples;
	uint8 *_samplesBuf;
};

#endif
