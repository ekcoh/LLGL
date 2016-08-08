/*
 * LinuxWindow.h
 *
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_LINUX_WINDOW_H__
#define __LLGL_LINUX_WINDOW_H__


#include <LLGL/Window.h>
#include <X11/Xlib.h>

#if 1//!!!
#   include <GL/gl.h>
#   include <GL/glx.h>
#endif


namespace LLGL
{


class LinuxWindow : public Window
{

    public:

        LinuxWindow(const WindowDescriptor& desc);
        ~LinuxWindow();

        void SetPosition(const Point& position) override;
        Point GetPosition() const override;

        void SetSize(const Size& size, bool useClientArea = true) override;
        Size GetSize(bool useClientArea = true) const override;

        void SetTitle(const std::wstring& title) override;
        std::wstring GetTitle() const override;

        void Show(bool show = true) override;
        bool IsShown() const override;

        WindowDescriptor QueryDesc() const override;

        void Recreate(const WindowDescriptor& desc) override;
        
        const void* GetNativeHandle() const override;
        
        /* ----- Extended functions ----- */
        
        inline ::Display* GetDisplay() const
        {
            return display_;
        }
        
        inline ::Window GetHandle() const
        {
            return wnd_;
        }
        
        inline XVisualInfo* GetVisual() const
        {
            return visual_;
        }

    private:

        void ProcessSystemEvents() override;

        void SetupDisplay();
        void SetupWindow();

        void ProcessKeyEvent(XEvent& event, bool down);
        void ProcessMouseKeyEvent(XEvent& event, bool down);
        void PostMouseKeyEvent(Key key, bool down);

        WindowDescriptor    desc_;

        ::Display*          display_    = nullptr;
        ::Colormap          colorMap_;
        ::Window            wnd_;
        //::Cursor            cursor_;
        XVisualInfo*        visual_     = nullptr;

};


} // /namespace LLGL


#endif



// ================================================================================
