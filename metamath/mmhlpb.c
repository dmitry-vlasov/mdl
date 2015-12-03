#ifndef MMHLPB_C_
#define MMHLPB_C_

/*****************************************************************************/
/*        Copyright (C) 2009  NORMAN MEGILL  nm at alum.mit.edu              */
/*            License terms:  GNU General Public License                     */
/*****************************************************************************/
/*34567890123456 (79-character line to adjust editor window) 2345678901234567*/

/* Part 2 of help file for Metamath */

/* To add a new help entry, you must add the command syntax to mmcmdl.c
   as well as adding it here. */

#include <string.h>
#include <stdio.h>
#include "mmvstr.h"
#include "mmdata.h"
#include "mmcmds.h"
#include "mmhlpb.h"

void help2(vstring helpCmd)
{

printHelp = !strcmp(helpCmd, "HELP");
H("Welcome to Metamath.  Here are some general guidelines.");
H("");
H("To make the most effective use of Metamath, you should become familiar");
H("with the Metamath book.  In particular, you will need to learn");
H("the syntax of the Metamath language.");
H("");
H("For help using the command line, type HELP CLI.");
H("For help invoking Metamath, type HELP INVOKE.");
H("For a summary of the Metamath language, type HELP LANGUAGE.");
H("For help getting started, type HELP DEMO.");
H("For help exploring the data base, type HELP EXPLORE.");
H("For help creating a LaTeX file, type HELP TEX.");
H("For help creating Web pages, type HELP HTML.");
H("For help proving new theorems, type HELP PROOF_ASSISTANT.");
H("For a list of help topics, type HELP ? (to force an error message).");
H("For current program settings, type SHOW SETTINGS.");
H("For a simple but general-purpose ASCII file manipulator, type TOOLS.");
H("To exit Metamath, type EXIT (or its synonym QUIT).");
H("");
H(cat("If you need technical support, contact Norman Megill at nm",
    "@", "alum.mit.edu.", NULL));
H("Copyright (C) 2006 Norman Megill");
H("License terms:  GNU General Public License");
H("");

printHelp = !strcmp(helpCmd, "HELP INVOKE");
H("To invoke Metamath from a Unix/Linux/MacOSX prompt, assuming that the");
H("Metamath program is in the current directory, type");
H("");
H("  bash$ ./metamath");
H("");
H("To invoke Metamath from a Windows DOS or Command Prompt, assuming that");
H("the Metamath program is in the current directory (or in a directory");
H("included in the Path system environment variable), type");
H("");
H("  C:\\metamath>metamath");
H("");
H("To use command-line arguments at invocation, the command-line arguments");
H("should be a list of Metamath commands, surrounded by quotes if they");
H("contain spaces.  In Windows DOS, the surrounding quotes must be double");
H("(not single) quotes.  For example, to read the database set.mm, verify");
H("all proofs, and exit the program, type (under Unix)");
H("");
H("  bash$ ./metamath 'read set.mm' 'verify proof *' exit");
H("");
H("Note that in Unix, any directory path with /'s must be surrounded by");
H("quotes so Metamath will not interpret the / as a command qualifier.  So");
H("if set.mm is in the /tmp directory, use for the above example");
H("");
H("  bash$ ./metamath 'read \"/tmp/set.mm\"' 'verify proof *' exit");
H("");
H("For convenience, if the command-line has one argument and no spaces in");
H("the argument, the command is implicitly assumed to be READ.  In this one");
H("special case, /'s are not interpreted as command qualifiers, so you don't");
H("need quotes around a Unix file name.  Thus");
H("");
H("  bash$ ./metamath /tmp/set.mm");
H("");
H("and");
H("");
H("  bash$ ./metamath \"read '/tmp/set.mm'\"");
H("");
H("are equivalent.");
H("");

printHelp = !strcmp(helpCmd, "HELP CLI");
H("The Metamath program was first developed on a VAX/VMS system, and some");
H("aspects of its command line behavior reflect this heritage.  Hopefully");
H(
"you will find it reasonably user-friendly once you get used to it.");
H("");
H("Each command line is a sequence of English-like words separated by");
H("spaces, as in SHOW SETTINGS.  Command words are not case sensitive, and");
H("only as many letters are needed as are necessary to eliminate ambiguity;");
H("for example, \"sh se\" would work for the command SHOW SETTINGS.  In some");
H("cases arguments such as file names, statement labels, or symbol names are");
H("required; these are case-sensitive (although file names may not be on");
H("some operating systems).");
H("");
H("A command line is entered by typing it in then pressing the <return> key.");
H("");
H("To find out what commands are available, type ? at the MM> prompt,");
H("followed by <return>. (This is actually just a trick to force an error");
H("message, since ? is not a legal command.)");
H("");
H("To find out the choices at any point in a command, press <return> and you");
H("will be prompted for them.  The default choice (the one selected if you");
H("just press <return>) is shown in brackets (<>).");
H("");
H("You may also type ? in place of a command word to force Metamath to tell");
H("you what the choices are.  The ? method won't work, though, if a");
H("non-keyword argument such as a file name is expected at that point,");
H("because the CLI will think the ? is the argument.");
H("");
H("Some commands have one or more optional qualifiers that modify the");
H("behavior of the command.  Qualifiers are indicated by a slash (/), such as");
H("in READ set.mm / VERIFY.  Spaces are optional around / and =.  If you need");
H("to use / or = in a command argument, as in a Unix file name, put single");
H("or double quotes around the command argument.  See the last section of");
H("HELP LET for more information on special characters in arguments.");
H("");
H("The OPEN LOG command will save everything you see on the screen, and is");
H("useful to help you recover should something go wrong in a proof, or if");
H("you want to document a bug.");
H("");
H("If the response to a command is more than a screenful, you will be");
H("prompted to '<return> to continue, Q to quit, or S to scroll to end'.");
H("Q will complete the command internally but suppress further output until");
H("the next \"MM>\" prompt.  S will suppress further pausing until the next");
H("\"MM>\" prompt.  After the first screen, you can also choose B to go back");
H("a screenful.  Note that B may also be entered at the \"MM>\" prompt");
H("immediately after a command to scroll back through the output of that");
H("command.  Scrolling can be disabled with SET SCROLL CONTINUOUS.");
H("");
H("**Warning**  Pressing CTRL-C will abort the Metamath program");
H("unconditionally.  This means any unsaved work will be lost.");
H("");
H("A command line enclosed in quotes is executed by your operating system.");
H("See HELP SYSTEM.");
H("");
H("Some additional CLI-related features are explained by:");
H("    HELP SET ECHO");
H("    HELP SET SCROLL");
H("    HELP SET WIDTH");  /* 18-Nov-05 nm Was SCREEN_WIDTH */
H("    HELP SET HEIGHT"); /* 18-Nov-05 nm New */
H("    HELP SUBMIT");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW MEMORY");
H("Syntax:  SHOW MEMORY");
H("");
H("This command shows the available memory left.  It may not be meaningful");
H("on machines with virtual memory.");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW SETTINGS");
H("Syntax:  SHOW SETTINGS");
H("");
H("This command shows the state of various parameters.");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW LABELS");
H("Syntax:  SHOW LABELS <label-match> [/ ALL] [/ LINEAR]");
H("");
H("This command shows the labels of $a and $p statements that match");
H("<label-match>.  <label-match> may contain * and ? wildcard characters;");
H("see HELP SEARCH for wildcard matching rules.");
H("");
H("Optional qualifier:");
H("    / ALL - Include matches for $e and $f statement labels.");
H("    / LINEAR - Display only one label per line.  This can be useful for");
H("        building scripts in conjunction with the TOOLS utility.");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW SOURCE");
H("Syntax:  SHOW SOURCE <label>");
H("");
H("This command shows the ASCII source code associated with a statement.");
H("Normally you should use SHOW STATEMENT for a more meaningful display,");
H("but SHOW SOURCE can be used to see statements with multiple comments");
H("and to see the exact content of the Metamath database.");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW STATEMENT");
/* 27-Jul-05 nm Added SIMPLE_TEX */
H(
"Syntax:  SHOW STATEMENT <label> [/ COMMENT] [/ FULL] [/ TEX] [/ SIMPLE_TEX]");
H("             [/ HTML] [/ ALT_HTML] [/ BRIEF_HTML] [/ BRIEF_ALT_HTML]");
H("             [/ MNEMONICS]");
H("");
H("");
H("This command provides information about a statement.  Only statements");
H("that have labels ($f, $e, $a, and $p) may be specified.  If <label>");
H("contains wildcard characters, all matching statements will be displayed");
H("displayed in the order they occur in the database.  The wildcard \"*\"");
H("matches 0 or more characters, and the wildcard \"?\" matches any single");
H("character.  Multiple statement labels (with or without wildcards) may be");
H("separated by commas (with no spaces) in <label>.");
H("");
H("By default, only the statement and its $e hypotheses are shown, and if");
H("the label has wildcards, only $a and $p statements are shown.");
H("");
H("Optional qualifiers (only one qualifier at a time is allowed):");
H("    / COMMENT - This qualifier includes the comment that immediately");
H("        precedes the statement.");
H("    / FULL - Show complete information about each statement, and show all");
H("        statements matching <label> (including $e and $f statements).");
H("    / TEX - This qualifier will write the statement information to the");
H("        LaTeX file previously opened with OPEN TEX.");
/* 27-Jul-05 nm Added SIMPLE_TEX */
H("    / SIMPLE_TEX - The same as / TEX, except that LaTeX macros are not");
H("        used for formatting equations, allowing easier manual edits of");
H("        the output.");
H("    / HTML - This qualifier invokes a special mode of SHOW STATEMENT which");
H("        creates a Web page for the statement.  It may not be used with");
H("        any other qualifier.  See HELP HTML for more information.");
H("    / ALT_HTML, / BRIEF_HTML, / BRIEF_ALT_HTML - See HELP HTML for more");
H("        information on these.");
H("    / NO_VERSIONING - When used with / HTML or the 3 HTML qualifiers");
H("        above, a backup file suffixed with ~1 is not created (i.e. the");
H("        previous version is overwritten).");
/* 12-May-2009 nm  Added MNEMONICS */
H("    / MNEMONICS - Produces the output file mnemosyne.txt for use with");
H("        Mnemosyne http://www.mnemosyne-proj.org/principles.php.  Should");
H("        not be used with any other qualifier.");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW PROOF");
H("Syntax:  SHOW PROOF <label> [<qualifiers (see below)>]");
H("");
H("This command displays the proof of the specified $p statement various");
H("formats.  The <label> may contain \"*\" (0-or-more-character match) and");
H("\"?\" (single-character match) wildcard characters to match multiple");
H("statements.  Without any qualifiers, only the logical steps will be shown");
H("(i.e. syntax construction steps will be omitted), in indented format.");
H("");
H("Most of the time, you will use");
H("    SHOW PROOF <label>");
H("to see just the proof steps corresponding to logical deduction.");
H("");
H("Optional qualifiers:");
H("    / ESSENTIAL - the proof tree is trimmed of all $f hypotheses before");
H("        being displayed.  (This is the default, and it is redundant to");
H("        specify it.)");
H("    / ALL - the proof tree is not trimmed of all $f hypotheses before");
H("        being displayed.  / ESSENTIAL and / ALL are mutually exclusive.");
H("    / FROM_STEP <step> - the display starts at the specified step.  If");
H("        this qualifier is omitted, the display starts at the first step.");
H("    / TO_STEP <step> - the display ends at the specified step.  If this");
H("        qualifier is omitted, the display ends at the last step.");
H("    / DEPTH <number> - Only steps at less than the specified proof");
H("        tree depth are displayed.  Useful for obtaining an overview of");
H("        the proof.");
H("    / REVERSE - the steps are displayed in reverse order.");
H("    / RENUMBER - when used with / ESSENTIAL, the steps are renumbered");
H("        to correspond only to the essential steps.");
H("    / TEX - the proof is converted to LaTeX and stored in the file opened");
H("        with OPEN TEX.");
H("    / LEMMON - The proof is displayed in a non-indented format known");
H("        as Lemmon style, with explicit previous step number references.");
H("        If this qualifier is omitted, steps are indented in a tree format.");
H("    / START_COLUMN <number> - Overrides the default column at which");
H("        the formula display starts in a Lemmon style display.  Affects");
H("        only displays using the / LEMMON qualifier.");
H("    / NORMAL - The proof is displayed in normal format suitable for");
H("        inclusion in a source file.  May not be used with any other");
H("        qualifier.");
/*
H("    / PACKED - The proof is displayed in packed format suitable for");
H("        inclusion in a source file.  May not be used with any other");
H("        qualifier.");
*/
H("    / COMPRESSED - The proof is displayed in compressed format");
H("        suitable for inclusion in a source file.  May not be used with");
H("        any other qualifier.");
H("    / STATEMENT_SUMMARY - Summarizes all statements (like a brief SHOW");
H("        STATEMENT) used by the proof.  May not be used with any other");
H("        qualifier except / ESSENTIAL.");
H("    / DETAILED_STEP <step> - Shows the details of what is happening at");
H("        a specific proof step.  May not be used with any other qualifier.");
H("");


printHelp = !strcmp(helpCmd, "HELP MIDI");
H("Syntax:  MIDI <label> [/ PARAMETER \"<parameter string>\"]");
H("");
H("This will create a MIDI sound file for the proof of <label>, where <label>");
H("is one of the $p statement labels shown with SHOW LABELS.  The <label> may");
H("contain \"*\" (0-or-more-character match) and \"?\" (single-character");
H("match) wildcard characters to match multiple statements.  For each matched");
H("label, a file will be created called <label>.txt which is a MIDI source");
H("file that can be converted to a MIDI binary file with the \"t2mf\" utility");
H("that can be obtained at:");
H("   http://www.hitsquad.com/smm/programs/mf2t/download.shtml");
H("Note: the MS-DOS version t2mf.exe only handles old-style 8.3 file names,");
H("so files such as pm2.11.txt are rejected and must be renamed to");
H("e.g. pm2_11.txt.");
H("");
H("The parameters are:");
H("");
H("  f = make the tempo fast (default is slow).");
H("  m = make the tempo medium (default is slow).");
H("      Both \"f\" and \"m\" should not be specified simultaneously.");
H("  s = syncopate the melody by silencing repeated notes, using");
H("      a method selected by whether the \"h\" parameter below is also");
H("      present (default is no syncopation).");
H("  h = allow syncopation to hesitate i.e. all notes in a");
H("      sequence of repeated notes are silenced except the first (default");
H("      is no hesitation, which means that every other note in a repeated");
H("      sequence is silenced - this makes it sound slightly more rhythmic).");
H("      The \"h\" parameter is meaningful only if the \"s\" parameter above");
H("      is also present.");
H("  w = use only the white keys on the piano keyboard (default");
H("      is potentially to use all keys).");
H("  b = use only the black keys on the piano keyboard (default");
H("      is all keys).  Both \"w\" and \"b\" should not be specified");
H("      simultaneously.");
H("  i = use an increment of one keyboard note per proof");
H("      indentation level.  The default is to use an automatic increment of");
H("      up to four notes per level based on the dynamic range of the whole");
H("      song.");
H("");
H("Quotes around the parameter string are optional if it has no spaces.");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW NEW_PROOF");
H("Syntax:  SHOW NEW_PROOF [<qualifiers (see below)]");
H("");
H("This command (available only in Proof Assistant mode) displays the proof");
H("in progress.  It is identical to the SHOW PROOF command, except that the");
H("statement is not specified (since it is the statement being proved) and");
H("following qualifiers are not available:");
H("    / STATEMENT_SUMMARY");
H("    / DETAILED_STEP");
H("");
H("Also, the following additional qualifiers are available:");
H("    / UNKNOWN - Shows only steps that have no statement assigned.");
H("    / NOT_UNIFIED - Shows only steps that have not been unified.");
H("");
H("Note that / ALL, / DEPTH, / UNKNOWN, and / NOT_UNIFIED may");
H("be used in any combination; each of them effectively filters out (or");
H("\"unfilters\" in the case of / ALL) additional steps from the proof");
H("display.");
H("");
H("See also:  SHOW PROOF");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW USAGE");
H("Syntax:  SHOW USAGE <label-match> [/ RECURSIVE]");
H("");
H("This command lists the statements whose proofs make direct reference to");
H("the statement(s) specified by <label-match>.  <label-match> may contain *");
H("and ? wildcard characters; see HELP SEARCH for wildcard matching rules.");
H("");
H("Optional qualifiers:");
H("    / RECURSIVE - Also include include statements whose proof ultimately");
H("        depend on the statement specified.");
H("    / ALL - Include $e and $f statements.  Without / ALL, $e and $f");
H("        statements are excluded when <label-match> contains wildcard");
H("        characters.");
H("");


printHelp = !strcmp(helpCmd, "HELP SHOW TRACE_BACK");
H("Syntax:  SHOW TRACE_BACK <label-match> [/ ESSENTIAL] [/ AXIOMS] [/ TREE]");
H("             [/ DEPTH <number>] [/ COUNT_STEPS]");
H("");
H("This command lists all statements that the proof of the $p statement(s)");
H("specified by <label-match> depends on.  <label-match> may contain *");
H("and ? wildcard characters; see HELP SEARCH for wildcard matching rules.");
H("");
H("Optional qualifiers:");
H("    / ESSENTIAL - Restrict the trace-back to $e hypotheses of proof");
H("        trees.");
H("    / AXIOMS - List only the axioms that the proof ultimately depends on.");
H("    / TREE - Display the trace-back in an indented tree format.");
H("    / DEPTH - Restrict the / TREE traceback to the specified indentation");
H("        depth.");
H("    / COUNT_STEPS - Counts the number of steps the proof would have if");
H("        fully expanded back to axioms.  If / ESSENTIAL is specified,");
H("        expansions of floating hypotheses are not counted.");
H("");


printHelp = !strcmp(helpCmd, "HELP SEARCH");
H("Syntax:  SEARCH <label-match> \"<symbol-match>\" [/ ALL] [/ COMMENTS]");
H("             [/ JOIN]");
H("");
H("This command searches all $a and $p statements matching <label-match>");
H("for occurrences of <symbol-match>.");
H("");
H("A * in <label-match> matches any zero or more characters in a label.");
H("A ? in <label-match> matches any single character.  For example,");
H("SEARCH p?4* \"ph <-> ph\" will check statements whose labels have p and 4");
H("in their first and third character positions, and display them when their");
H("math strings contain \"ph <-> ph\".");
H("");
H("A $* in <symbol-match> matches any sequence of zero or more characters");
H("in the statement's math string.  A $? in <symbol-match> matches any");
H("single character in the statement's math string.  The quotes surrounding");
H("<symbol-match> may be single or double quotes.  For example,");
H("SEARCH * 'E. $? A. $? $?$? -> $* E.' using the set.mm database will find");
H("\"E. x A. y ph -> A. y E. x ph\".  As this example shows, $? is");
H("particularly useful when you don't know the variable names used in a");
H("theorem of interest.");
H("");
H("Note 1. Multiple statements (and wildcard patterns) may be specified");
H("using a comma-separated list for <label-match>, with no spaces around");
H("the commas.  Example:  SEARCH ax-*,df-* 'E. x'.");
H("");
H("Note 2. The first and last characters of <label-match>, if they are not");
H("wildcards, will be matched against the first and last characters of the");
H("label.  In contrast, <symbol-match> is a substring match, i.e. it has");
H("implicit $* wildcards before and after it.");
H("");
H("Note 3. An \"unofficial\" <symbol-match> feature is that $ and ? can be");
H("used instead of $* and $? for brevity.  The drawback is that matching a");
H("math symbol containing a ? character may yield additional unwanted");
H("matches, but this was felt to be a minor nuisance outweighed by the");
H("convenience of this feature.  (Note that $ is not a legal math symbol");
H("character, which is the reason for its use in the official $* and $?");
H("wildcards.)  The official wildcards are processed before the unofficial");
H("ones, so that $? will not be interpreted as $ followed by ?.");
H("");
H("Optional qualifiers:");
H("    / ALL - Also search $e and $f statements.");
H("    / COMMENTS - Search the comment that immediately precedes each");
H("        label-matched statement for <symbol-match>, instead of searching");
H("        the statement's math string.  In this mode, <symbol-match> is an");
H("        arbitrary, non-case-sensitive character string.  Wildcards in");
H("        <symbol-match> are not implemented in this mode.");
H("    / JOIN - In the case of a $a or $p statement, prepend its $e");
H("        hypotheses for searching.  / JOIN has no effect in / COMMENTS");
H("        mode.");
H("");
H("See the last section of HELP LET for how to handle quotes and special");
H("characters.");
H("");


printHelp = !strcmp(helpCmd, "HELP SET ECHO");
H("Syntax:  SET ECHO ON or SET ECHO OFF");
H("");
H("The SET ECHO ON command will cause command lines to be echoed with any");
H("abbreviations expanded.  While learning the Metamath commands, this");
H("feature will show you the exact command that your abbreviated input");
H("corresponds to.  This is also useful to assist creating robust command");
H("files (see HELP SUBMIT) from your log file (see HELP OPEN LOG).  To make");
H("it easier to extract these lines, \"!\" (which you will discard) is");
H("prepended to each echoed command line.");
H("");


printHelp = !strcmp(helpCmd, "HELP SET SCROLL");
H("Syntax:  SET SCROLL PROMPTED or SET SCROLL CONTINUOUS");
H("");
H("The Metamath command line interface starts off in the PROMPTED mode,");
H("which means that you will prompted to continue or quit after each");
H("screenful of a long listing.  In CONTINUOUS mode, long listings will be");
H("scrolled without pausing.");
H("");


printHelp = !strcmp(helpCmd, "HELP SET WIDTH"); /* 18-Nov-05 nm Revised */
H("Syntax:  SET WIDTH <number>");
H("");
H("Metamath assumes the width of your screen is 79 characters.  If your");
H("screen is wider or narrower, this command lets you to change the screen");
H("width.  A larger width is advantageous for logging proofs to an output");
H("file to be printed on a wide printer.  A smaller width may be necessary");
H("on some terminals; in this case, the wrapping of the information");
H("messages may sometimes seem somewhat unnatural, however.  In LaTeX, there");
H("is normally a maximum of 61 characters per line with typewriter font.");
H("");
H("Note:  The default width is 79 because Windows Command Prompt issues a");
H("spurious blank line after an 80-character line (try it!).");
H("");
H("Note:  This command was SET SCREEN_WIDTH prior to Version 0.07.9.");
H("");


printHelp = !strcmp(helpCmd, "HELP SET HEIGHT"); /* 18-Nov-05 nm New */
H("Syntax:  SET HEIGHT <number>");
H("");
H("Metamath assumes your screen height is 24 lines of characters.  If your");
H("screen is taller or shorter, this command lets you to change the number");
H("of lines at which the display pauses and prompts you to continue.");
H("");


printHelp = !strcmp(helpCmd, "HELP SET UNIFICATION_TIMEOUT");
H("Syntax:  SET UNIFICATION_TIMEOUT <number>");
H("");
H("(This command affects the Proof Assistant only.)");
H("");
H("Sometimes the Proof Assistant will inform you that a unification timeout");
H("occurred.  This may happen when you try to UNIFY formulas with many");
H("unknown variables, since the time to compute unifications may grow");
H("exponentially with the number of variables.  If you want Metamath to try");
H("harder (and you're willing to wait longer) you may increase this");
H("parameter.  SHOW SETTINGS will show you the current value.");
H("");


printHelp = !strcmp(helpCmd, "HELP SET EMPTY_SUBSTITUTION");
H("Syntax:  SET EMPTY_SUBSTITUTION ON or SET EMPTY_SUBSTITUTION OFF");
H("");
H("(This command affects the Proof Assistant only.  It may be issued");
H("outside of the Proof Assistant.)");
H("");
H("The Metamath language allows variables to be substituted with empty");
H("symbol sequences.  However, in most formal systems this will never happen");
H("in a valid proof.  Allowing for this possibility increases the likelihood");
H("of ambiguous unifications during proof creation.  The default is that");
H("empty substitutions are not allowed; for formal systems requiring them,");
H("you must SET EMPTY_SUBSTITUTION ON.  Note that empty substitutions are");
H("always permissable in proof verification (VERIFY PROOF...) outside the");
H("Proof Assistant.  (See the MIU system in the Metamath book for an example");
H("of a system needing empty substitutions; another example would be a");
H("system that implements a Deduction Rule and in which deductions from");
H("empty assumption lists would be permissable.)");
H("");


printHelp = !strcmp(helpCmd, "HELP SET SEARCH_LIMIT");
H("Syntax:  SET SEARCH_LIMIT <number>");
H("");
H("(This command affects the Proof Assistant only.)");
H("");
H("This command sets a parameter that determines when the IMPROVE command");
H("in Proof Assistant mode gives up.  If you want IMPROVE to search harder,");
H("you may increase it.  The SHOW SETTINGS command tells you its current");
H("value.");
H("");


printHelp = !strcmp(helpCmd, "HELP SET JEREMY_HENTY_FILTER");
H("Syntax:  SET JEREMY_HENTY_FILTER ON or SET JEREMY_HENTY_FILTER OFF");
H("");
H("(This command affects the Proof Assistant only.)");
H("");
H("The \"Henty filter\" is an ingenious algorithm suggested by Jeremy Henty");
H("that reduces the number of ambiguous unifications by eliminating");
H("\"equivalent\" ones in a sense defined by Henty.  Normally this filter");
H("is ON, and the only reason to turn it off would be for debugging.");
H("");


printHelp = !strcmp(helpCmd, "HELP VERIFY PROOF");
H("Syntax:  VERIFY PROOF <label-match> [/ SYNTAX_ONLY]");
H("");
H("This command verifies the proofs of the specified statements.");
H("<label-match> may contain * and ? wildcard characters to verify more than");
H("one proof; for example \"abc?def*\" will match all labels beginning with");
H("\"abc\" followed by any single character followed by \"def\".");
H("VERIFY PROOF * will verify all proofs in the database.");
H("");
H("Optional qualifier:");
H("    / SYNTAX_ONLY - This qualifier will perform a check of syntax and RPN");
H("        stack violations only.  It will not verify that the proof is");
H("        correct.");
H("");
H("Note: READ, followed by VERIFY PROOF *, will ensure the database is free");
H("from errors in Metamath language but will not check the markup language");
H("in comments.  One way to check the markup language is WRITE THEOREM_LIST.");
H("");


printHelp = !strcmp(helpCmd, "HELP SUBMIT");
H("Syntax:  SUBMIT <filename> [/ SILENT]");
H("");
H("This command causes further command lines to be taken from the specified");
H("command file.  Note that any line beginning with an exclamation point (!)");
H("is treated as a comment (i.e. ignored).  Also note that the scrolling");
H("of the screen output is continuous, so you may want to open a log file");
H("(see HELP OPEN LOG) to record the results that fly by on the screen.");
H("After the lines in the command file are exhausted, Metamath returns to");
H("its normal user interface mode.");
H("");
H("SUBMIT commands are not allowed inside of the command file, i.e. SUBMIT");
H("is not recursive.");
H("");
H("Optional qualifier:");
H("    / SILENT - This qualifier suppresses the screen output of the SUBMIT");
H("        command.  The output will still be recorded in any log file that");
H("        has been opened with OPEN LOG (or is opened inside the command");
H("        file itself).  The screen output of any operating system commands");
H("        inside the command file (see HELP SYSTEM) is not suppressed.");


printHelp = !strcmp(helpCmd, "HELP SYSTEM");
H("A line enclosed in single or double quotes will be executed by your");
H("computer's operating system, if it has such a feature.  For example, on a");
H("GNU/Linux system,");
H("    MM> 'ls | less -EX'");
H("will list disk directory contents.  Note that this feature will not work");
H("on the pre-OSX Macintosh, which does not have a command line interface.");
H("");
H("For your convenience, the trailing quote is optional, for example:");
H("    MM> 'ls | less -EX");
H("");


printHelp = !strcmp(helpCmd, "HELP PROVE");
H("Syntax:  PROVE <label>");
H("");
H("This command will enter the Proof Assistant, which will allow you to");
H("create or edit the proof of the specified statement.");
H("");
H("See also:  HELP PROOF_ASSISTANT and HELP EXIT");
H("");


printHelp = !strcmp(helpCmd, "HELP MM-PA");
H("See HELP PROOF_ASSISTANT");
H("");


printHelp = !strcmp(helpCmd, "HELP MORE");
H("Syntax:  MORE <filename>");
H("");
H("This command will type (i.e. display) the contents of an ASCII file on");
H("your screen.  (This command is provided for convenience but is not very");
H("powerful.  See HELP SYSTEM to invoke your operating system's command to");
H("do this, such as \"less -EX\" in Linux.)");
H("");


printHelp = !strcmp(helpCmd, "HELP FILE SEARCH");
H("Syntax:  FILE SEARCH <filename> \"<search string>\" [/ FROM_LINE");
H("             <number>] [/ TO_LINE <number>]");
H("");
H("This command will search an ASCII file for the specified string in");
H("quotes, within an optional range of line numbers, and display the result");
H("on your screen.  The search is case-insensitive.  (This command is");
H("deprecated.  See HELP SYSTEM to invoke your operating system's");
H("equivalent command, such as \"grep\" in Linux.)");
H("");


printHelp = !strcmp(helpCmd, "HELP WRITE SOURCE");
H("Syntax:  WRITE SOURCE <filename>");
H("");
H("Optional qualifier:");
H("");
H("    / CLEAN - Suppresses the output of any theorem that has been flagged");
H("        with a question mark (?) placed in the date comment field at the");
H("        end of its proof, for example \"$( [?31-Oct-00] $)\".  This lets");
H("        you strip out proofs under development so that a \"clean\"");
H("        version of the database can be generated for official release.");
H("        Note:  Hypotheses are not stripped, only $p statements.");
H("        Spurious date comment fields of the suppressed theorems may also");
H("        remain.");
H("");
H("This command will write the contents of the Metamath database into a file.");
H("Note:  The present version of Metamath will not split the database into");
H("its constituent files included with $[ $] keywords.  Instead it will write");
H("the entire database as one big file.");
H("");

printHelp = !strcmp(helpCmd, "HELP WRITE THEOREM_LIST");
H("Syntax:  WRITE THEOREM_LIST");
H("");
H("Optional qualifier:");
H("    / THEOREMS_PER_PAGE <number> - specifies the number of theorems to");
H("        write per output file");
H("");
H("This command writes a list of the $a and $p statements in the database");
H("into web page files called \"mmtheorems.html\", \"mmtheorems2.html\",");
H("\"mmtheorems3.html\", etc.  If / THEOREMS_PER_PAGE is omitted, the number");
H("of theorems (and other statements) per page defaults to 100.");
H("[Warning:  A value other than 100 for THEOREMS_PER_PAGE will cause the");
H("list to become out of sync with the \"Related theorems\" links on the");
H("web pages for individual theorems.  This may be corrected in a future");
H("version.]");
H("");
H("The first output file, \"mmtheorems.html\", includes a Table of Contents.");
H("An entry is triggered in the database by \"$(\" immediately followed by a");
H("new line starting with either \"#*#*\" (for a section break) or \"=-=-\"");
H("(for a subsection break).  The line following that one that will be used");
H("for the table of contents entry, after trimming spaces.  In between two");
H("successive statements that generate web pages (i.e. $a and $p");
H("statements), only the last section and/or subsection break will be used,");
H("and any subsection break before a section break will be ignored.  See the");
H("set.mm database file for examples.");
H("");
H("[Warning: For matching, white space is NOT ignored.  There should be no");
H("spaces between \"$(\" and the end of the line.  This may be allowed in");
H("a future version, if a request is made to N. Megill.]");
H("");

printHelp = !strcmp(helpCmd, "HELP WRITE BIBLIOGRAPHY");
H("Syntax:  WRITE BIBLIOGRAPHY <filename>");
H("");
H("This command reads an HTML bibliographic cross-reference file, normally");
H("called \"mmbiblio.html\", and updates it per the bibliographic links in");
H("the database comments.  The file is updated between the HTML comment");
H("lines \"<!-- #START# -->\" and \"<!-- #END# -->\".  A name in brackets");
H("in a database comment is assumed to be a bibliographic reference, and");
H("this command searches backwards in the comment for a keyword such as");
H(" \"Theorem\" and forwards for a page number.  Example: \"Theorem 3.1 of");
H("[Monk] p. 22\". (See the \"set.mm\" database file for examples.  The");
H("syntax is somewhat loose and subject to refinement.)  The original input");
H("file is renamed to \"<filename>~1\"");
H("");

printHelp = !strcmp(helpCmd, "HELP WRITE RECENT_ADDITIONS");
H("Syntax:  WRITE RECENT_ADDITIONS <filename>");
H("");
H("Optional qualifier:");
H("    / LIMIT <number> - specifies the number of most recent theorems to");
H("        write to the output file");
H("");
H("This command reads an HTML Recent Additions file, normally");
H("called \"mmrecent.html\", and updates it with the descriptions of the");
H("most recently added theorems to the database.  If / LIMIT is omitted, the");
H("number of theorems written defaults to 100.  The file is updated between");
H("the HTML comment lines \"<!-- #START# -->\" and \"<!-- #END# -->\".  The");
H("original input file is renamed to \"<filename>~1\"");
H("");
H("Recent theorems are identified using the date in the first comment");
H("immediately following the proof, which is expected to be in the format");
H("\"$( [dd-mmm-yyyy] $)\", where \"dd\" may be 1 or 2 digits, e.g.");
H("\"$( [31-Dec-2007] $)\".");
H("");

printHelp = !strcmp(helpCmd, "HELP ASSIGN");
H("Syntax:  ASSIGN <step> <label>");
H("         ASSIGN FIRST <label>");  /* 11-Dec-05 nm */
H("         ASSIGN LAST <label>");
H("");
H("Optional qualifier:");
H("    / NO_UNIFY - do not prompt user to select a unification if there is");
H("        more than one possibility.  This is useful for noninteractive");
H("        command files.  Later, the user can UNIFY ALL / INTERACTIVE.");
H("        (The assignment will still be automatically unified if there is");
H("        only one possibility.)");
H("");
H("This command, available in the Proof Assistant only, assigns an unknown");
H("step (one with ? in the SHOW NEW_PROOF listing) with the statement");
H("specified by <label>.  The assignment will not be allowed if the");
H("statement cannot be unified with the step.");
H("");
H("If FIRST is specified instead of <step> number, the first step that is");
H("shown by SHOW NEW_PROOF / UNKNOWN will be used.");
H("");
H("If LAST is specified instead of <step> number, the last step that is");
H("shown by SHOW NEW_PROOF / UNKNOWN will be used.  This can be useful for");
H("building a proof with a command file (see HELP SUBMIT).");
H("");
H("If the <step> is zero or negative, the -<step>th from last unknown step,");
H("as shown by SHOW NEW_PROOF / UNKNOWN, will be used.  ASSIGN -1 <label>");
H("will assign the penultimate unknown step,  ASSIGN -2 <label> the");
H("antepenultimate, and ASSIGN 0 <label> is the same as ASSIGN LAST <label>.");
H("");

printHelp = !strcmp(helpCmd, "HELP REPLACE");
H("Syntax:  REPLACE <step> <label>");
H("");
H("This command, available in the Proof Assistant only, replaces the");
H("statement assigned to <step> with statement <label>.  The replacement");
H("will be done only if the subproof at <step> has contains steps (with no");
H("dummy variables) that exactly match the hypotheses of <label>.");
H("");

printHelp = !strcmp(helpCmd, "HELP MATCH");
H("Syntax:  MATCH STEP <step> [/ MAX_ESSENTIAL_HYP <number>]");
H("    or:  MATCH ALL [/ ESSENTIAL_ONLY] [/ MAX_ESSENTIAL_HYP <number>]");
H("");
H("This command, available in the Proof Assistant only, shows what");
H("statements can be unified with the specified step(s).");
H("");
H("Optional qualifiers:");
H("    / MAX_ESSENTIAL_HYP <number> - filters out of the list any statements");
H("        with more than the specified number of $e hypotheses");
H("    / ESSENTIAL_ONLY - in the MATCH ALL statement, only the steps that");
H("        would be listed in SHOW NEW_PROOF display are matched.");
H("");


printHelp = !strcmp(helpCmd, "HELP LET");
H("Syntax:  LET VARIABLE <variable> = \"<symbol sequence>\"");
H("         LET STEP <step> = \"<symbol sequence>\"");
H("");
H("These commands, available in the Proof Assistant only, assign an unknown");
H("variable or step with a specific symbol sequence.  They are useful in the");
H("middle of creating a proof, when you know what should be in the proof");
H("step but the unification algorithm doesn't yet have enough information");
H("to completely specify the unknown variables.  An \"unknown\" variable is");
H("one which has the form $nn in the proof display, such as $1, $2, etc.");
H("The <symbol sequence> may contain other unknown variables if desired.");
H("Examples:");
H("    LET VARIABLE $32 = \" A = B \"");
H("    LET VARIABLE $32 = \" A = $35 \"");
H("    LET STEP 10 = \" |- x = x \"");
H("    LET STEP -2 = \" |- ( $7 <-> ph ) \"");
H("");
H("Any symbol sequence will be accepted for the LET VARIABLE command.  In");
H("LET STEP, only symbol sequences that can be unified with the step are");
H("accepted.  LET STEP assignments are prefixed with \"=(User)\" in most");
H("SHOW NEW_PROOF displays.");
H("");
H("If <step> is zero or negative, the -<step>th from last unknown step,");
H("as shown by SHOW NEW_PROOF / UNKNOWN, will be used.  LET STEP 0 will");
H("assign the last unknown step, LET STEP -1 <label> will assign the");
H("penultimate unknown step, etc.  If <step> is positive, LET STEP may be");
H("used to assign known as well as unknown steps.");
H("");
H("The LET commands are somewhat dangerous in that they \"zap\" the proof");
H("with information that can only be verified when the proof is built up");
H("further. If you make an error, the INITIALIZE commands can help undo what");
H("you did.  See HELP INITIALIZE.");
H("");
H("Note that SAVE PROOF does not save any LET VARIABLE or LET STEP");
H("assignents.  However, IMPROVE ALL prior to SAVE PROOF will usually");
H("preserve the information for steps with no unknown variables.");
H("");
H("Quotes and special characters in command-line arguments");
H("-------------------------------------------------------");
H("");
H("You can use single quotes to surround the math symbol string argument of");
H("a LET or SEARCH command when the argument contains a double quote.");
H("For example,");
H("  MM-PA> LET VARIABLE $2 = '( F \" A )'");
H("");
H("The trailing quote may be omitted for convenience, to save typing:");
H("  MM-PA> LET VARIABLE $2 = '( F \" A )");
H("");
H("If a math symbol string has both single and double quotes, you must");
H("use the prompted completion feature by pressing RETURN where the symbol");
H("string would go.  Quotes aren't needed (and must not be used) around");
H("the answer to a prompted completion question.");
H("  MM-PA> LET VARIABLE $2 =");
H("  With what math symbol string? ( `' F \" A )");
H("");
H("Quotes are optional around any math symbol string containing a single");
H("symbol and and not containing \"=\", \"/\", a single quote, or a double");
H("quote:");
H("  MM-PA> LET VARIABLE $17 = ph");
H("");
H("Unquoted \"=\" and \"/\" are special in a command line in that they are");
H("implicitly surrounded by white space:");
H("  MM-PA> LET VARIABLE $17=ph");
H("  MM-PA> SHOW NEW_PROOF/UNKNOWN");
H("");


printHelp = !strcmp(helpCmd, "HELP UNIFY");
H("HELP UNIFY");
H("Syntax:  UNIFY STEP <step>");
H("         UNIFY ALL [/ INTERACTIVE]");
H("");
H("These commands, available in the Proof Assistant only, unify the source");
H("and target of the specified step(s). If you specify a specific step, you");
H("will be prompted to select among the unifications that are possible.  If");
H("you specify ALL, only those steps with unique unifications will be");
H("unified.");
H("");
H("Optional qualifier for UNIFY ALL:");
H("    / INTERACTIVE - You will be prompted to select among the unifications");
H("        that are possible for any steps that do not have unique");
H("        unifications.");
H("");
H("See also SET UNIFICATION_TIMEOUT.  The default is 100000, but increasing");
H("it to 1000000 can help difficult cases.  The LET VARIABLE command to");
H("manually assign unknown variables also helps difficult cases.");
H("");


printHelp = !strcmp(helpCmd, "HELP INITIALIZE");
H("Syntax:  INITIALIZE ALL");
H("         INITIALIZE USER");
H("         INITIALIZE STEP <step>");
H("");
H("These commands, available in the Proof Assistant only, \"de-unify\" the");
H("target and source of a step (or all steps), as well as the hypotheses of");
H("the source, and make all variables in the source and the source's");
H("hypotheses unknown.  This command is useful to help recover when an");
H("ASSIGN mistake resulted in incorrect unifications.  After you DELETE the");
H("incorrect ASSIGN, use INITIALIZE ALL then UNIFY ALL / INTERACTIVE to");
H("recover the state before the mistake.");
H("");
H("INITIALIZE ALL will void all LET VARIABLE assignments as well as de-unify");
H("all targets and sources.  INITIALIZE USER will delete all LET STEP");
H("assignments but will not de-unify.  INITIALIZE STEP will do all of these");
H("actions for the specified step.");
H("");
H("After de-unification and variable deassignment, proof steps that are");
H("completely known will be automatically re-unified.  If you want to");
H("de-unify these, use DELETE FLOATING_HYPOTHESES then INITIALIZE ALL.");
H("");
H("See also:  UNIFY and DELETE");
H("");


printHelp = !strcmp(helpCmd, "HELP DELETE");
H("Syntax:  DELETE STEP <step>");
H("         DELETE ALL");
H("         DELETE FLOATING_HYPOTHESES");
H("");
H("These commands are available in the Proof Assistant only. The DELETE STEP");
H("command deletes the proof tree section that branches off of the specified");
H("step and makes the step become unknown.  DELETE ALL is equivalent to");
H("DELETE STEP <step> where <step> is the last step in the proof (i.e. the");
H("beginning of the proof tree).");
H("");
H("DELETE FLOATING_HYPOTHESES will delete all sections of the proof that");
H("branch off of $f statements.  It is sometimes useful to do this before");
H("an INITIALIZE command to recover from an error.  Note that once a proof");
H("step with a $f hypothesis as the target is completely known, the IMPROVE");
H("command can usually fill in the proof for that step.");
H("");
H("Warning:  There is currently no \"undo\" from DELETE.  Save your work!");
H("");


printHelp = !strcmp(helpCmd, "HELP IMPROVE");
H("Syntax:  IMPROVE <step> [/ DEPTH <number>] [/ NO_DISTINCT]");
                                                           /* 26-Aug-2006 nm */
H("         IMPROVE ALL [/ DEPTH <number>] [/ NO_DISTINCT]");
H("         IMPROVE FIRST [/ DEPTH <number>] [/ NO_DISTINCT]");
                                                             /* 11-Dec-05 nm */
H("         IMPROVE LAST [/ DEPTH <number>] [/ NO_DISTINCT]");
H("");
H("These commands, available in the Proof Assistant only, try to");
H("find proofs automatically for unknown steps whose symbol sequences are");
H("completely known.  They are primarily useful for filling in proofs of $f");
H("hypotheses.  The search will be restricted to statements having no $e");
H("hypotheses.");
H("");
H("IMPROVE FIRST is the same as IMPROVE <step> using the first step that is");
H("shown by SHOW NEW_PROOF / UNKNOWN.");
H("");
H("IMPROVE LAST is the same as IMPROVE <step> using the last step that is");
H("shown by SHOW NEW_PROOF / UNKNOWN.");
H("");
H("If the <step> is zero or negative, the -<step>th from last unknown step,");
H("as shown by SHOW NEW_PROOF / UNKNOWN, will be used.  IMPROVE -1 will use");
H("the penultimate unknown step,  IMPROVE -2 the antepenultimate, and");
H("IMPROVE 0 is the same as IMPROVE LAST.");
H("");
H("Optional qualifier:");
H("    / DEPTH <number> - This qualifier will cause the search to include");
H("        statements with $e hypotheses (but no new variables in the $e");
H("        hypotheses), provided that the backtracking has not exceeded the");
H("        specified depth.  **WARNING**:  Try DEPTH 1, then 2, then 3, etc");
H("        in sequence because of possible exponential blowups.  Save your");
H("        work before trying DEPTH greater than 1!!!");
H("    / NO_DISTINCT - Skip trial statements that have $d requirements.");
H("        This qualifier will prevent assignments that might violate $d");
H("        requirements but it also could miss possible legal assignments.");
H("");
H("Note:  If memory is limited, IMPROVE ALL on a large proof may overflow");
H("memory.  If you use SET UNIFICATION_TIMEOUT 1 before IMPROVE ALL,");
H("there will usually be sufficient improvement to later easily recover and");
H("completely IMPROVE the proof on a larger computer.  Warning:  Once");
H("memory has overflowed, there is no recovery.  If in doubt, save the");
H("intermediate proof (SAVE NEW_PROOF then WRITE SOURCE) before IMPROVE ALL.");
H("");
H("See also:  HELP SET SEARCH_LIMIT");
H("");


printHelp = !strcmp(helpCmd, "HELP MINIMIZE_WITH");
H("Syntax:  MINIMIZE_WITH <label> [/ BRIEF] [/ ALLOW_GROWTH] [/ NO_DISTINCT]");
H("");
H("This command, available in the Proof Assistant only, checks whether");
H("the proof can be shortened by using earlier $p or $a statements matching");
H("<label>, and if so, shortens the proof.  <label> can contain wildcards");
H("(* and ?) to test more than one statement, but each statement is still");
H("tested independently from the others.  Warning:  MINIMIZE_WITH does not");
H("check for $d violations, so SAVE PROOF then VERIFY PROOF should be run");
H("afterwards to check for them.");
H("");
H("Optional qualifiers:");
H("    / BRIEF - The labels of statements that were tested but didn't reduce");
H("        the proof length will not be listed, for brevity.");
H("    / ALLOW_GROWTH - If a substitution is possible, it will be made even");
H("        if the proof length increases.  This is useful if we are just");
H("        updating the proof with a newer version of an obsolete theorem.");
H("    / NO_DISTINCT - Skip the trial statement if it has a $d requirement.");
H("        This qualifier is useful when <label> has wildcards, to prevent");
H("        illegal shortenings that would violate $d requirements.");
/* 7-Jan-06 nm - Added EXCEPT */
H("    / EXCEPT <skiplabel> - Skip trial statements matching <skiplabel>,");
H("        which may contain * and ? wildcard characters; see HELP SEARCH");
H("        for wildcard matching rules.  Note:  Multiple EXCEPT qualifiers");
H("        are not allowed; use wildcards instead.");
H("");


printHelp = !strcmp(helpCmd, "HELP SAVE PROOF");
H("Syntax:  SAVE PROOF <label> [/ NORMAL] [/ COMPRESSED]");
H("");
H("The SAVE PROOF command will reformat a proof in one of two formats and");
H("replace the existing proof in the database buffer.  It is useful for");
H("converting between proof formats.  Note that a proof will not be");
H("permanently saved until a WRITE SOURCE command is issued.  Multiple");
H("proofs may be saved by using wildcards (* and ?) in <label>.");
H("");
H("Optional qualifiers:");
H("    / NORMAL - The proof is saved in the basic format (i.e., as a sequence");
H("        of labels, which is the defined format of the basic Metamath");
H("        language).  This is the default format which is used if a");
H("        qualifier is omitted.");
/*
H("    / PACKED - The proof is saved in the packed format, which uses");
H("        local labels to avoid repetition of identical subproofs.");
*/
H("    / COMPRESSED - The proof is saved in the compressed format which");
H("        reduces storage requirements in a source file.");
H("");


printHelp = !strcmp(helpCmd, "HELP SAVE NEW_PROOF");
H("Syntax:  SAVE NEW_PROOF [/ NORMAL] [/ COMPRESSED]");
H("");
H("The SAVE NEW_PROOF command is available in the Proof Assistant only. It");
H("saves the proof in progress in the database buffer.  SAVE NEW_PROOF may be");
H("used to save a completed proof, or it may be used to save a proof in");
H("progress in order to work on it later.  If an incomplete proof is saved,");
H("any user assignments with LET STEP or LET VARIABLE will be lost, as will");
H("any ambiguous unifications that were resolved manually. To help make");
H("recovery easier, it is advisable to IMPROVE ALL before SAVE NEW_PROOF so");
H("that the incomplete proof will have as much information as possible.");
H("");
H("Note that the proof will not be permanently saved until a WRITE SOURCE");
H("command is issued.");
H("");
H("Optional qualifiers:");
H("    / NORMAL - The proof is saved in the NORMAL format (i.e., as a");
H("        sequence of labels, which is the defined format of the basic");
H("        Metamath language).  This is the default format which is used if a");
H("        qualifier is omitted.");
/*
H("    / PACKED - The proof is saved in the packed format, which uses");
H("        local labels to avoid repetition of identical subproofs.");
*/
H("    / COMPRESSED - The proof is saved in the compressed format which");
H("        reduces storage requirements in a source file.");
H("");


printHelp = !strcmp(helpCmd, "HELP DEMO");
H("For a quick demo that enables you to see Metamath do something, type");
H("the following:");
H("    READ set.mm");
H("    SHOW STATEMENT id1 /COMMENT");
H("    SHOW PROOF id1 /RENUMBER /LEMMON");
H("will show you a proof of \"P implies P\" directly from the axioms");
H("of propositional calculus.");
H("    SEARCH * \"distributive law\" /COMMENTS");
H("will show all the distributive laws in the database.");
H("    SEARCH * \"(_ $* u.\"");
H("will show all statements with subset then union in them.");
H("");

}

#endif /*MMHLPB_C_*/
