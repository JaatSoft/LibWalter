// =============================================================================
//
// libwalter ToolbarControl.h
//
// Base class for WToolbar controls
//
// Revision: 20070518
// Page width 80, tab width 4, encoding UTF-8, line endings LF.
//
// Original author:
//     Gabriele Biffi - http://www.biffuz.it/
// Contributors:
//
// Released under the terms of the MIT license.
//
// =============================================================================

#ifndef _TOOLBAR_CONTROL_H_
#define _TOOLBAR_CONTROL_H_

// BeOS headers
#include <Invoker.h>

// libwalter headers
#include "ToolbarItem.h"

// BeOS classes
class BView;

// libwalter classes
class WToolbar;

// =============================================================================
// WToolbarControl
// =============================================================================

class WToolbarControl : public WToolbarItem, public BInvoker {
friend class WToolbar;
private:
			void			_init_object(void);
			bool			fEnabled;
public:
							WToolbarControl(const char *name = NULL,
								BMessage *message = NULL);
							WToolbarControl(BMessage *archive);
	virtual					~WToolbarControl();
	// BArchivable hooks
	virtual	status_t		Archive(BMessage *archive,
								bool deep = true) const;
	static	BArchivable *	Instantiate(BMessage *archive);
	// Other methods
	virtual	void			AttachedToToolbar(void);
	virtual	void			DetachedFromToolbar(void);
	virtual	void			Draw(BView *canvas, BRect updateRect);
			bool			Enabled(void);
	virtual	void			GetPreferredSize(float *width,
								float *height);
	virtual	void			MouseDown(BPoint point);
	virtual	void			MouseMoved(BPoint point, uint32 transit,
								const BMessage *message);
	virtual	void			MouseUp(BPoint point);
			void			SetEnabled(bool enabled);
};

#endif // _TOOLBAR_CONTROL_H_