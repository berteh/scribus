/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/
#ifndef PICSEARCH_H
#define PICSEARCH_H

#include <qdialog.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <q3listbox.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qstringlist.h>

#include "scribusapi.h"
#include "picsearchbase.h"


/*! \brief Dialog for selecting one of all images founded.
It's called after image search Extras/Manage Pictures/ Click [Search] button for chosen
image frame item. */
class SCRIBUS_API PicSearch : public PicSearchBase
{ 
	Q_OBJECT

public:
	/*!
	\author Franz Schmid
	\brief Constructor for PicSearch.[dox?]. Used in Extras / Manage Pictures / Search function
	\param parent QWidget pointer to parent window
	\param fileName QString name of image
	\param avalableFiles QStringList List of Paths where an Image with the given Name is present
	*/
	PicSearch( QWidget* parent, const QString & fileName, const QStringList & avalableFiles);
	~PicSearch() {};

	//! \brief Currently selected image with its full path
	QString currentImage;

private slots:
	/*!
	\author Franz Schmid
	\brief If preview is desired (checked) then the image preview is shown and generated, otherwise hidden.
	*/
	void previewCheckBox_clicked();
	/*!
	\author Franz Schmid
	\brief When image is selected from the ListBox then the image preview may be shown and the Use button is enabled.
	\param c QListBoxItem
	*/
	void foundFilesBox_clicked(Q3ListBoxItem *c);
	/*!
	\author Franz Schmid
	\brief Generates image preview for the found Picture
	*/
	void createPreview();

signals:
	//! \brief Emitted when the pic for a row is replaced. Arg is row index.
	void rowPicChanged(unsigned int);

protected:
	QSize minS;
};

#endif // PICSEARCH_H
