#pragma once
#include "RustedJar/Input.h"

namespace RustedJar {
	class WindowsInput : public Input {
	protected:
		virtual bool IsKeyPressedImpl(int keyCode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}