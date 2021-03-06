#ifndef CREATECOMMITMENT_H
#define CREATECOMMITMENT_H

#include <Interval.h>
#include <QCheckBox>
#include <QDateEdit>
#include <QIntValidator>
#include <QLineEdit>
#include <QWidget>
#define WRITING_STRING "Writing"
#define MUSIC_STRING "Compose Music"
#define CUSTOM_STRING "Custom"

namespace Ui {
class CreateCommitmentQWidget;
}

/**
 * @brief The CreateCommitmentQWidget class
 */
class CreateCommitmentQWidget : public QWidget {
    Q_OBJECT

public:
    explicit CreateCommitmentQWidget(QWidget *parent = nullptr);
    ~CreateCommitmentQWidget();

    QCheckBox *getKeyboardCheckBox();
    QCheckBox *getAudioCheckBox();
    Ui::CreateCommitmentQWidget *getUI();
    QIntValidator validator{ (0, 999, this) };
    QString getCommitmentName();
    QDate getStartDate();
    QDate getEndDate();
    util::Interval getInterval();

private slots:
    void dropDownTaskSlot(const QString &);
    void createCommitmentButtonSlot();
    void backButtonSlot();
    void on_createCommitmentQFrame_destroyed();

private:
    Ui::CreateCommitmentQWidget *ui;
};

#endif // CREATECOMMITMENT_H
