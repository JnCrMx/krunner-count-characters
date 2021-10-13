#include "count.h"

#include <QApplication>
#include <QClipboard>

void CharacterCount::match(Plasma::RunnerContext &context)
{
	auto query = context.query();
	auto charCount = query.length();
	auto wordCount = query.count(' ')+1;

	QByteArray byteArray = query.toUtf8();
	auto byteCount = byteArray.size();

	Plasma::QueryMatch bytes(this);
	bytes.setText(QString::number(byteCount)+" byte(s)");
	bytes.setData(QString::number(byteCount));
	bytes.setIcon(QIcon::fromTheme("enumerate"));
	context.addMatch(bytes);

	Plasma::QueryMatch chars(this);
	chars.setText(QString::number(charCount)+" character(s)");
	chars.setData(QString::number(charCount));
	chars.setIcon(QIcon::fromTheme("enumerate"));
	context.addMatch(chars);

	Plasma::QueryMatch words(this);
	words.setText(QString::number(wordCount)+" word(s)");
	words.setData(QString::number(wordCount));
	words.setIcon(QIcon::fromTheme("enumerate"));
	context.addMatch(words);
}

void CharacterCount::run(const Plasma::RunnerContext &, const Plasma::QueryMatch &match)
{
	QApplication::clipboard()->setText(match.data().toString());
}

K_EXPORT_PLASMA_RUNNER_WITH_JSON(CharacterCount, "count.json")

#include "count.moc"
