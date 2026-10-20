#!/usr/bin/env python3
"""Recount solutions and rewrite the tables in README.md.

Topics     = top-level folders (Array, Math, ...)
Problems   = sub-folders inside a topic that contain a solution file
Languages  = solution files grouped by file extension
"""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "README.md"

LANGUAGES = {
    ".c": "C", ".cpp": "C++", ".java": "Java", ".py": "Python",
    ".js": "JavaScript", ".ts": "TypeScript", ".go": "Go",
    ".rs": "Rust", ".cs": "C#", ".kt": "Kotlin", ".swift": "Swift",
    ".rb": "Ruby", ".sql": "SQL", ".dart": "Dart", ".php": "PHP",
    ".scala": "Scala", ".r": "R", ".sh": "Bash",
}
IGNORED_DIRS = {"scripts", "node_modules"}


def topic_name(folder: str) -> str:
    return folder.replace("-", " ").replace(" And ", " and ")


def scan():
    topics, languages = {}, {}
    for topic in sorted(ROOT.iterdir()):
        if not topic.is_dir() or topic.name.startswith(".") or topic.name in IGNORED_DIRS:
            continue
        count = 0
        for problem in topic.iterdir():
            if not problem.is_dir():
                continue
            files = [f for f in problem.iterdir()
                     if f.is_file() and f.suffix.lower() in LANGUAGES]
            if not files:
                continue
            count += 1
            for f in files:
                lang = LANGUAGES[f.suffix.lower()]
                languages[lang] = languages.get(lang, 0) + 1
        if count:
            topics[topic_name(topic.name)] = count
    return topics, languages


def table(header, rows):
    lines = [f"| {header} | Count |", "|---|---|"]
    lines += [f"| {name} | {n} |" for name, n in rows]
    return "\n".join(lines)


def replace_block(text, tag, content):
    pattern = re.compile(rf"(<!-- {tag}:START -->)(.*?)(<!-- {tag}:END -->)", re.S)
    if not pattern.search(text):
        raise SystemExit(f"Marker {tag} not found in README.md")
    return pattern.sub(lambda m: f"{m.group(1)}\n{content}\n{m.group(3)}", text)


def main():
    topics, languages = scan()
    by_count = lambda d: sorted(d.items(), key=lambda kv: (-kv[1], kv[0]))

    text = README.read_text(encoding="utf-8")
    text = replace_block(text, "TOTAL", f"**Total problems solved: {sum(topics.values())}**")
    text = replace_block(text, "LANGUAGES", table("Language", by_count(languages)).replace("| Count |", "| Files |"))
    text = replace_block(text, "TOPICS", table("Topic", by_count(topics)).replace("| Count |", "| Problems |"))
    README.write_text(text, encoding="utf-8")
    print(f"Updated README: {sum(topics.values())} problems, {sum(languages.values())} files")


if __name__ == "__main__":
    main()
