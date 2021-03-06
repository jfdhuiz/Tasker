#ifndef LIVESESSION_H
#define LIVESESSION_H

#include <QWidget>
#include <TaskerPerf/perftimer.h>
namespace Ui {
class LiveSession;
}

class LiveSession : public QWidget {
    Q_OBJECT

public:
    explicit LiveSession(QWidget *parent = nullptr);
    ~LiveSession();
private slots:
    void updateTimeUI();
    void congratsSlot();


private:
    Ui::LiveSession *ui;
    Perf::PerfTimer liveSessionPerfTimer{};
    Perf::PerfTimer liveSessionPerfTimer1{};
    Perf::PerfTimer liveSessionPerfTimer2{};
    Perf::PerfTimer liveSessionPerfTimer3{};
};

#endif // LIVESESSION_H
