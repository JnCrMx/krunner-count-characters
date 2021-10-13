#ifndef COUNT_H
#define COUNT_H

#include <KConfigCore/KConfig>
#include <KConfigCore/KConfigGroup>

#include <KRunner/AbstractRunner>

class CharacterCount : public Plasma::AbstractRunner
{
	Q_OBJECT

	public:
		CharacterCount(QObject *parent, const KPluginMetaData &pluginMetaData, const QVariantList &args)
			: Plasma::AbstractRunner(parent, pluginMetaData, args)
		{
			setObjectName(QLatin1String("Count Characters"));
			setPriority(HighestPriority);
		}
		~CharacterCount() override = default;

		void match(Plasma::RunnerContext &) override;
		void run(const Plasma::RunnerContext &, const Plasma::QueryMatch &) override;
};

#endif