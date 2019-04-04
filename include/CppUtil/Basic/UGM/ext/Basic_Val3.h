#ifndef _CPPUTIL_BASIC_MATH_UGM_EXT_BASIC_VAL3_H_
#define _CPPUTIL_BASIC_MATH_UGM_EXT_BASIC_VAL3_H_

#include <CppUtil/Basic/UGM/Val3.h>
#include <CppUtil/Basic/UGM/ext/Basic_Val.h>

#include <CppUtil/Basic/Math.h>

namespace CppUtil {
	namespace Basic {
		namespace EXT {
			template <typename T, typename ImplT>
			class Basic_Val_Base<3, T, ImplT> : public Val<3, T> {
			public:
				using Val<3, T>::Val;

			public:
				const ImplT Abs() const {
					return ImplT(
						abs(x),
						abs(y),
						abs(z)
					);
				}

				ImplT & AbsSelf() {
					x = abs(x);
					y = abs(y);
					z = abs(z);
					return *static_cast<ImplT*>(this);
				}

				static const ImplT Lerp(const ImplT & s0, const ImplT & s1, T t) {
					return ImplT(
						Math::Lerp(s0.x, s1.x, t),
						Math::Lerp(s0.y, s1.y, t),
						Math::Lerp(s0.z, s1.z, t)
					);
				}

				static const ImplT Min(const ImplT & lhs, const ImplT & rhs) {
					return ImplT(
						std::min(lhs.x, rhs.x),
						std::min(lhs.y, rhs.y),
						std::min(lhs.z, rhs.z)
					);
				}

				static const ImplT Max(const ImplT & lhs, const ImplT & rhs) {
					return ImplT(
						std::max(lhs.x, rhs.x),
						std::max(lhs.y, rhs.y),
						std::max(lhs.z, rhs.z)
					);
				}
			};
		}
	}
}

#endif // !_CPPUTIL_BASIC_MATH_UGM_EXT_BASIC_VAL3_H_