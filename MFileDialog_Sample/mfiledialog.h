#ifndef MFILEDIALOG_H
#define MFILEDIALOG_H

#include <QObject>
#include <QFileDialog>

class MFileDialog : public QFileDialog
{
    Q_OBJECT
public:
    explicit MFileDialog(QWidget *parent = 0);
    ~MFileDialog();

public slots:
    void onChiose();
};

#endif // MFILEDIALOG_H
