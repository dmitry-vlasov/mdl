/*****************************************************************************/
/* Project name:    del - mathematics development language                   */
/* File Name:       del_owl_man_lexer_WhitespaceScaner.hpp                   */
/* Description:     whitespace scaner                                        */
/* Copyright:       (c) 2006-2009 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#ifndef DEL_OWL_MAN_LEXER_WHITESPACE_SCANER_HPP_
#define DEL_OWL_MAN_LEXER_WHITESPACE_SCANER_HPP_

#include "del/owl/man/lexer/del_owl_man_lexer_CommentScaner.hpp"

namespace del {
namespace owl {
namespace man {
namespace lexer {

class WhitespaceScaner : public Object {
public :
	typedef
		CommentScaner :: Comments_
		Comments_;

	WhitespaceScaner (Source&);
	virtual ~ WhitespaceScaner();

	void scan();
	bool emptyline() const;
	Comments_& comments();

	// object :: Object interface
	virtual void commitSuicide();
	virtual Size_t getVolume() const;
	virtual Size_t getSizeOf() const;
	virtual void show (String&) const;

private :
	bool commentBegins();

	Source& source_;
	CommentScaner commentScaner_;
	bool emptyline_;
};

}
}
}
}

#endif /*DEL_OWL_MAN_LEXER_WHITESPACE_SCANER_HPP_*/