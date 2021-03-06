#include "qvinfodialog.h"
#include "ui_qvinfodialog.h"
#include <QDateTime>
#include <QLocale>
#include <QMimeDatabase>
#include <QtGlobal>

QVInfoDialog::QVInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QVInfoDialog)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->addAction(ui->actionRefresh);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

QVInfoDialog::~QVInfoDialog()
{
    delete ui;
}

void QVInfoDialog::setInfo(const QFileInfo &value, const int &value2, const int &value3, const int &value4, const int &value5)
{
    selectedFileInfo = value;
    width = value2;
    height = value3;
    frameCount = value4;
    nextFrameDelay = value5;
    updateInfo();
}

void QVInfoDialog::on_actionRefresh_triggered()
{
    updateInfo();
}

void QVInfoDialog::updateInfo()
{
    QLocale locale = QLocale::system();
    QMimeDatabase mimedb;
    QMimeType mime = mimedb.mimeTypeForFile(selectedFileInfo.filePath(), QMimeDatabase::MatchContent);
    const float megapixels = float(int((static_cast<float>((width*height)))/1000000 * 10 + 0.5f)) / 10 ;
    const float length = nextFrameDelay*frameCount;
    const int fps = qRound(static_cast<float>(frameCount)/(length/1000.0f));

    ui->nameLabel->setText(selectedFileInfo.fileName());
    ui->typeLabel->setText(mime.name());
    ui->locationLabel->setText(selectedFileInfo.path());
    ui->sizeLabel->setText(locale.formattedDataSize(selectedFileInfo.size()) + " (" + locale.toString(selectedFileInfo.size()) + tr(" bytes)"));
    ui->modifiedLabel->setText(selectedFileInfo.lastModified().toString(locale.dateTimeFormat()));
    ui->dimensionsLabel->setText(QString::number(width) + " x " + QString::number(height) + " (" + QString::number(megapixels) + tr("MP)"));
    if (frameCount != 0)
    {
        ui->label_8->show();
        ui->label_7->show();
        ui->label_3->show();
        ui->framesLabel->show();
        ui->fpsLabel->show();
        ui->lengthLabel->show();
        ui->framesLabel->setText(QString::number(frameCount));
        ui->fpsLabel->setText(QString::number(fps) + " fps");
        ui->lengthLabel->setText(QString::number(nextFrameDelay*frameCount) + "ms");
    }
    else
    {
        ui->framesLabel->hide();
        ui->fpsLabel->hide();
        ui->lengthLabel->hide();
        ui->label_8->hide();
        ui->label_7->hide();
        ui->label_3->hide();
    }
}
