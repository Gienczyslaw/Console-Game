#pragma once

/// <summary>
/// Enum class that was created special for Game. Constains direction.
/// </summary>
enum class Direction
{
	LEFT = 'a',
	UP = 'w',
	RIGHT = 'd',
	DOWN = 's'
};

/// <summary>
/// Changes directories:
/// LEFT - RIGHT,
/// UP - DOWN,
/// RIGHT - LEFT,
/// DOWN - UP.
/// </summary>
/// <param name="toReverse">- Directory to reverse.</param>
Direction reverseDirection(Direction toReverse);