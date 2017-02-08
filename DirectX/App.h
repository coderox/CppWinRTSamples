#pragma once

#include "pch.h"
#include "Common\DeviceResources.h"
#include "DirectXMain.h"

namespace DirectX
{
	// Main entry point for our app. Connects the app with the Windows shell and handles application lifecycle events.
	struct App : winrt::implements<App, winrt::Windows::ApplicationModel::Core::IFrameworkView>
	{
	public:
		App();
		
		// IFrameworkView Methods.
		virtual void Initialize(winrt::Windows::ApplicationModel::Core::CoreApplicationView applicationView);
		virtual void SetWindow(winrt::Windows::UI::Core::CoreWindow window);
		virtual void Load(winrt::hstring entryPoint);
		virtual void Run();
		virtual void Uninitialize();

	protected:
		// Application lifecycle event handlers.
		void OnActivated(winrt::Windows::ApplicationModel::Core::CoreApplicationView applicationView, winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs args);
		void OnSuspending(winrt::Windows::IInspectable sender, winrt::Windows::ApplicationModel::SuspendingEventArgs args);
		void OnResuming(winrt::Windows::IInspectable  sender, winrt::Windows::IInspectable args);

		// Window event handlers.
		void OnWindowSizeChanged(winrt::Windows::UI::Core::CoreWindow sender, winrt::Windows::UI::Core::WindowSizeChangedEventArgs args);
		void OnVisibilityChanged(winrt::Windows::UI::Core::CoreWindow sender, winrt::Windows::UI::Core::VisibilityChangedEventArgs args);
		void OnWindowClosed(winrt::Windows::UI::Core::CoreWindow sender, winrt::Windows::UI::Core::CoreWindowEventArgs args);

		// DisplayInformation event handlers.
		void OnDpiChanged(winrt::Windows::Graphics::Display::DisplayInformation sender, winrt::Windows::IInspectable args);
		void OnOrientationChanged(winrt::Windows::Graphics::Display::DisplayInformation sender, winrt::Windows::IInspectable  args);
		void OnDisplayContentsInvalidated(winrt::Windows::Graphics::Display::DisplayInformation sender, winrt::Windows::IInspectable args);

	private:
		std::shared_ptr<DX::DeviceResources> m_deviceResources;
		std::unique_ptr<DirectXMain> m_main;
		bool m_windowClosed;
		bool m_windowVisible;
	};
}

struct Direct3DApplicationSource : winrt::implements<Direct3DApplicationSource, winrt::Windows::ApplicationModel::Core::IFrameworkViewSource>
{
	winrt::Windows::ApplicationModel::Core::IFrameworkView CreateView();
private:
	DirectX::App m_app;
};
